/**
 * 
 * This the very first version of LRU Cache implementation by myself
 * It is hard to maintain 
 * I have learned from AI that using dummy head and tail nodes can simplify the code significantly
 * 
 */

#include <vector>
#include <list>
#include <unordered_map>
#include <stdexcept>

using namespace std;

struct double_linked_list_node {
    int key;
    int value;
    double_linked_list_node* prev;
    double_linked_list_node* next;
    
    double_linked_list_node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

#define NOT_FOUND -1

class LRUCache {
public:
    LRUCache(int capacity): count_(0), usage_order_head_(nullptr), usage_order_tail_(nullptr) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) { 
            return NOT_FOUND;
        }

        auto node = it->second;
        if (usage_order_head_ == node) {
            return node->value;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node == usage_order_tail_) {
            usage_order_tail_ = node->prev;
        }

        node->prev = nullptr;
        node->next = usage_order_head_;
        if (usage_order_head_ != nullptr) {
            usage_order_head_->prev = node;
        }
        usage_order_head_ = node;

        return node->value;
    }
    
    void put(int key, int value) {
        if (get(key) != NOT_FOUND) {
            cache_[key]->value = value;
            return;
        }

        if (count_ == capacity_) {
            evict_lru();
        }

        auto new_node = new double_linked_list_node(key, value);
        new_node->next = usage_order_head_;

        if (usage_order_head_ != nullptr) {
            usage_order_head_->prev = new_node;
        }
        usage_order_head_ = new_node;

        if (usage_order_tail_ == nullptr) {
            usage_order_tail_ = new_node;
        }

        cache_[key] = new_node;
        count_++;
    }

private:
    int count_;
    int capacity_;
    double_linked_list_node* usage_order_head_;
    double_linked_list_node* usage_order_tail_;
    unordered_map<int, double_linked_list_node*> cache_;

    void evict_lru() {
        if (usage_order_tail_ == nullptr) {
            return;
        }

        auto node_to_evict = usage_order_tail_;
        if (node_to_evict->prev != nullptr) {
            node_to_evict->prev->next = nullptr;
            usage_order_tail_ = node_to_evict->prev;
        } else {
            usage_order_head_ = nullptr;
            usage_order_tail_ = nullptr;
        }

        cache_.erase(node_to_evict->key);
        delete node_to_evict;
        count_--;
    }
};
