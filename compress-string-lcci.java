class Solution {
    public String compressString(String S) {
        String tmp = "";
        int cnt = 0;
        for (int i = 0; i < S.length(); i++) {
            if (i == 0) {
                tmp += S.charAt(i);
                cnt++;
                continue;
            }
            if (S.charAt(i) != S.charAt(i - 1)) {
                tmp += cnt;
                cnt = 1;
                tmp += S.charAt(i);
            } else {
                cnt++;
            }
        }
        tmp += cnt;
        if (tmp.length() >= S.length())
            return S;
        else
            return tmp;
    }
}