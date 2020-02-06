class Solution {
    public int[] plusOne(int[] digits) {
        int flag = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            if (flag == 1) {
                digits[i] += 1;
                flag = 0;
            }
            if (digits[i] >= 10) {
                digits[i] -= 10;
                flag = 1;
            }
        }
        if (flag == 0)
            return digits;
        else {
            int[] res = new int[digits.length + 1];
            res[0] = 1;
            return res;
        }
    }
}