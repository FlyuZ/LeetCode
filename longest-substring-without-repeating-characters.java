class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty())
            return 0;
        int maxlen = 1, index = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = index; j < i; j++) { //
                if (s.charAt(i) == s.charAt(j)) {
                    index = j + 1;
                    break;
                }
            }
            if (maxlen < i - index + 1)
                maxlen = i - index + 1;
        }
        return maxlen;
    }
}
