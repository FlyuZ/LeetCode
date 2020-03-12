class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int i = 0; i < A.length; i++)
            sum += A[i];
        if (sum % 3 != 0)
            return false;
        sum /= 3;
        int curSum = 0, cnt = 0;
        for (int i = 0; i < A.length - 1; i++) {
            curSum += A[i];
            if (curSum == sum) {
                cnt++;
                if (cnt == 2)
                    return true;
                curSum = 0;
            }
        }
        return false;
    }
}