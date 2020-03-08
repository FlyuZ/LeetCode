class Solution {
    public int numTimesAllBlue(int[] light) {
        int cnt = 0;
        int max = 0;
        int[] index = new int[light.length + 1];
        for (int i = 0; i < light.length; i++) {
            index[light[i]] = 1;
            max = Math.max(max, light[i]);
            for (int j = 1; j <= max; j++) {
                if (index[j] == 0)
                    break;
                if (j == max)
                    cnt++;
            }
        }
        return cnt;
    }
}