#include <queue>
#include <vector>

using std::vector;
using std::queue;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adjacency(numCourses, vector<int>());
    queue<int> courses_can_take;
    initialize(adjacency, indegree, courses_can_take, numCourses, prerequisites);

    queue<int> courses;
    while (!courses_can_take.empty()) {
      int dc = courses_can_take.front();
      courses_can_take.pop();

      for (int c : adjacency[dc]) {
        indegree[c]--;
        if (indegree[c] == 0) {
          courses_can_take.push(c);
        }
      }

      courses.push(dc);
    }

    return courses.size() == numCourses;
  }

 private:
  void initialize(vector<vector<int>>& adjacency, 
                  vector<int>& indegree, 
                  queue<int>& courses_can_take,
                  int numCourses,
                  vector<vector<int>>& prerequisites) {
    for (const auto& pair : prerequisites) {
      int cource = pair[0];
      int pre = pair[1];

      adjacency[pre].push_back(cource);
      indegree[cource]++;
    }
    
    for (int c = 0; c < numCourses; c++) {
      if (indegree[c] == 0) {
        courses_can_take.push(c);
      }
    }
  }
};
