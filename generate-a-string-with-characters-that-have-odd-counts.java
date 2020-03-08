class Solution {
    public String generateTheString(int n) {
        String s = "";
        if (n == 0)
            return s;
        else if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++)
                s += 'a';
            s += 'b';
        } else {
            for (int i = 0; i < n; i++)
                s += 'a';
        }
        return s;

    }
}