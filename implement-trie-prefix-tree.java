class Trie {
    private Trie[] next;
    private final int R = 26;
    private boolean isEnd;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        next = new Trie[R];
        isEnd = false;
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); i++) {
            char cur = word.charAt(i);
            if (node.next[cur - 'a'] == null)
                node.next[cur - 'a'] = new Trie();
            node = node.next[cur - 'a'];
        }
        node.isEnd = true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); i++) {
            char cur = word.charAt(i);
            if (node.next[cur - 'a'] == null)
                return false;
            node = node.next[cur - 'a'];
        }
        return node.isEnd;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); i++) {
            char cur = prefix.charAt(i);
            if (node.next[cur - 'a'] == null)
                return false;
            node = node.next[cur - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */