class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length <= 1)
            return intervals;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> res = new ArrayList<>();
        int i = 0;
        while (i < intervals.length) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            while (i + 1 < intervals.length && intervals[i + 1][0] <= r) {
                r = Math.max(r, intervals[i + 1][1]);
                i++;
            }
            res.add(new int[]{l, r});
            i++;
        }
        return res.toArray(new int[res.size()][2]);
    }
}