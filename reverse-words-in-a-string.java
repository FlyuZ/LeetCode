class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        String res = "";
        for (int i = words.length - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0)
                res += " ";
        }
        return res;
    }
}