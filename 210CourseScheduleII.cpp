class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    int *indegree = new int[numCourses](); //开辟空间并初始化为0(只能为0)
    queue<int> qu;
    vector<int> edge[numCourses];
    vector<int> ans;
    for (int i = 0; i < prerequisites.size(); i++) {
      indegree[prerequisites[i].first]++;
      edge[prerequisites[i].second].push_back(prerequisites[i].first);
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
      ans.push_back(v);
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
      return {};
    else
      return ans;
  }
};
