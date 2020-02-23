class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();

    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k,  1, new ArrayList<Integer>());
        return res;
    }

    void dfs(int n, int k, int index, ArrayList<Integer> tmp) {
        if (tmp.size() == k) {
            res.add(new ArrayList<Integer>(tmp));
            return;
        }
        for (int i = index; i <= n; i++) {
            tmp.add(i);
            dfs(n, k, i + 1, tmp);
            tmp.remove(tmp.size() - 1);
        }
    }
}