class Solution {
    public boolean isPalindrome(String s) {
        if (s.isEmpty())
            return true;
        s = s.toLowerCase();
        int len = s.length();
        int i=0, j = s.length();
        while(i<j){
            
        }
        for (int i = 0; i < len / 2; i++) {
            if (s.charAt(i) != s.charAt(len - i - 1)) {
                return false;
            }
        }
        return true;
    }
}