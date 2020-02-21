class Solution {
    public String getPermutation(int n, int k) {
        String s = "";
        List<Integer> candidates = new ArrayList<>();
        int[] factorials = new int[n + 1];
        factorials[0] = 1;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            candidates.add(i);
            fact *= i;
            factorials[i] = fact;
        }
        k -= 1;
        for (int i = n - 1; i >= 0; --i) {
            int index = k / factorials[i];
            s += candidates.remove(index);
            k -= index * factorials[i];
        }
        return s;
    }
}

class Solution {
    int cnt = 0;
    List<Integer> res;
    public String getPermutation(int n, int k) {
        int[] vis = new int[n + 1];
        dfs(n, k, new ArrayList<Integer>(), vis);
        String ans = "";
        for (Integer i : res) {
            ans += i;
        }
        return ans;
    }

    void dfs(int n, int k, ArrayList<Integer> tmp, int[] vis) {
        if (cnt > k)
            return;
        if (tmp.size() == n) {
            cnt++;
            if (cnt == k) {
                res = new ArrayList<Integer>(tmp);
            }
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                tmp.add(i);
                dfs(n, k, tmp, vis);
                vis[i] = 0;
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}