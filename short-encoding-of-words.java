class Solution {
    public int minimumLengthEncoding(String[] words) {
        Trie root = new Trie();
        int cnt = 0;
        Arrays.sort(words, (s1, s2) -> s2.length() - s1.length());
        for (String s : words) {
            cnt += root.insert(s);
        }
        return cnt;
    }

    class Trie {
        private Trie[] next = new Trie[26];
        private boolean isEnd = false;

        public Trie() {
        }

        public int insert(String word) {
            Trie node = this;
            boolean isNew = false;
            for (int i = word.length() - 1; i >= 0; i--) {
                char cur = word.charAt(i);
                if (node.next[cur - 'a'] == null) {
                    isNew = true;
                    node.next[cur - 'a'] = new Trie();
                }
                node = node.next[cur - 'a'];
            }
            node.isEnd = true;
            return isEnd ? word.length() + 1 : 0;
        }
    }
}
