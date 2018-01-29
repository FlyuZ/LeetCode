class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    int *indegree = new int[numCourses](); //开辟空间并初始化为0(只能为0)
    queue<int> qu;
    vector<int> edge[numCourses];
    for (int i = 0; i < prerequisites.size(); i++) {
      indegree[prerequisites[i].second]++;
      edge[prerequisites[i].first].push_pack(prerequisites[i].second);
    }
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        qu.push(i);
      }
    }
    int cnt = 0;
    while (!qu.empty()) {
      int v = qu.front();
      qu.pop();
      cnt++;
      for (int i = 0; i < edge[v].size(); i++) {
        int to = edge[v][i];
        indegree[to]--;
        if (indegree[to] == 0) {
          qu.push(to);
        }
      }
    }
    if (cnt < numCourses)
      return false;
    else
      return true;
  }
};
