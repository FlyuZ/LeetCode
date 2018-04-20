class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    map<string, int> mp;
    vector<string> ans;
    for (int i = 0; i < list1.size(); i++) {
      mp[list1[i]] = i;
    }
    int Min = 0x3f3f3f;
    for (int i = 0; i < list2.size(); i++) {
      if (mp.count(list2[i]) != 0) {
        if (mp[list2[i]] + i < Min) {
          Min = mp[list2[i]] + i;
          ans.clear();
          ans.push_back(list2[i]);
        } else if (mp[list2[i]] + i == Min) {
          ans.push_back(list2[i]);
        }
      }
    }
    return ans;
  }
};
