class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++){
          if(judge(i)){
            ans.push_back(i);
          }
        }
        return ans;
    }
    bool judge(int num){
      for(int i=num; i>0; i/=10){
        if(i%10==0 || num%(i%10)!=0){
          return false;
        }
      }
      return true;
    }
};
