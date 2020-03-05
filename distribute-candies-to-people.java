class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int sum = 0;
        int index = 0;
        int cnt = 1;
        while (sum != candies) {
            if (sum + cnt > candies)
                cnt = candies - sum;
            ans[index] += cnt;
            sum += cnt;
            cnt++;
            index++;
            index %= num_people;
        }
        return ans;
    }
}