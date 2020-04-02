class LRUCache {
    class LinkedNode {
        int key;
        int value;
        LinkedNode prev;
        LinkedNode next;
    }

    HashMap<Integer, LinkedNode> cache = new HashMap<>();
    int size;
    int capacity;
    LinkedNode head, tail;

    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        head = new LinkedNode();
        tail = new LinkedNode();
        head.next = tail;
        tail.prev = head;
    }

    private void addNode(LinkedNode node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }

    private void removeNode(LinkedNode node) {
        LinkedNode prev = node.prev;
        LinkedNode next = node.next;
        prev.next = next;
        next.prev = prev;
    }

    private void moveToHead(LinkedNode node) {
        removeNode(node);
        addNode(node);
    }

    private LinkedNode popTail() {
        LinkedNode res = tail.prev;
        removeNode(res);
        return res;
    }

    public int get(int key) {
        LinkedNode node = cache.get(key);
        if (node == null)
            return -1;
        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        LinkedNode node = cache.get(key);
        if (node != null) {
            node.value = value;
            moveToHead(node);
        } else {
            LinkedNode newNode = new LinkedNode();
            newNode.key = key;
            newNode.value = value;
            cache.put(key, newNode);
            addNode(newNode);
            size++;
            if (size > capacity) {
                LinkedNode tail = popTail();
                cache.remove(tail.key);
                size--;
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */