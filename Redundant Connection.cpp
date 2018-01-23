class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int *parent = new int[2001];
        for(int i=0; i<2001; i++){
          parent[i] = i;
        }
        for(int i=0; i<edges.size(); i++){
          int x = Find(parent, edges[i][0]);
          int y = Find(parent, edges[i][1]);
          if(x == y)
              return edges[i];
          else
              parent[x] = y;
        }
        return {};
    }
    int Find(int parent[], int x){
      return parent[x] == x ? x : parent[x] = Find(parent, parent[x]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<int> parent(2001, -1);
      for(auto edge : edges){
        int x = Find(parent, edge[0]);
        int y = Find(parent, edge[1]);
        if(x == y)
            return edge;
        else
            parent[x] = y;
      }
      return {};
    }
    int Find(vector<int> &parent, int x){
      while(parent[x] != -1){
        x = parent[x];
      }
      return x;
    }
};
