class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.isEmpty())
            return 0;
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i < n - m + 1; i++){
            int j = 0;
            for( ; j < m; j++){
                if(haystack.charAt(i + j) !=  needle.charAt(j))
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
}