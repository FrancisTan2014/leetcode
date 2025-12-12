#include <unordered_map>
#include <stdexcept>

using namespace std;

#define NOT_FOUND -1

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity): count_(0) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
        capacity_ = capacity;
        head_ = new Node(-1, -1); // Dummy head
        tail_ = new Node(-1, -1); // Dummy tail
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) { 
            return NOT_FOUND;
        }

        Node* node = it->second;
        remove_node(node);
        add_node(node);

        return node->value;
    }

    void put(int key, int value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            Node* node = it->second;
            node->value = value;
            remove_node(node);
            add_node(node);
            return;
        } 

        if (count_ == capacity_) {
            Node* lru = tail_->prev;
            remove_node(lru);
            cache_.erase(lru->key);
            delete lru;
            count_--;
        }
        
        Node* new_node = new Node(key, value);
        add_node(new_node);
        cache_[key] = new_node;
        count_++;
    }

    ~LRUCache() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

private:
    int count_;
    int capacity_;
    Node* head_;
    Node* tail_;
    unordered_map<int, Node*> cache_;

    void add_node(Node* node) {
        head_->next->prev = node;
        node->next = head_->next;
        head_->next = node;
        node->prev = head_;
    }

    void remove_node(Node* node) {
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
};
