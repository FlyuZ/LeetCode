class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        vector<int> parent(len);
        for(int i=0; i<len; i++){
          parent[i] = i;
        }
        for(int i=0; i<len; i++){
          for(int j=i+1; j<len; j++){
            if(M[i][j] == 0){
              continue;
            }
            int x = unionFind(parent,i);
            int y = unionFind(parent,j);
            if(x != y){
              parent[x] = y;
            }
          }
        }
        int cnt = 0;
        for(int i=0; i<len; i++){
          if(parent[i] == i){
            cnt++;
          }
        }
        return cnt;
    }
    int unionFind(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = unionFind(parent, parent[x]);
    }
};
