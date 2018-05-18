class Solution {
  public List<String> letterCombinations(String digits) {
    List<String> ans = new ArrayList<>();
    if (digits.isEmpty()) {
      return ans;
    }
    String[] numToCh = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    bfs(digits, ans, 0, "", numToCh);
    return ans;
  }
  void bfs(String digits, List<String> ans, int cnt, String cur,
           String[] numToCh) {
    if (digits.length() == cnt) {
      ans.add(cur);
    } else {
      int num = digits.charAt(cnt) - '0';
      for (int i = 0; i < numToCh[num].length(); i++) {
        bfs(digits, ans, cnt + 1, cur + numToCh[num].charAt(i), numToCh);
      }
    }
  }
}
