/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        ListNode fir = head;
        while (fir != null) {
            if (hashMap.containsKey(fir.val)) {
                hashMap.put(fir.val, 1);
            } else {
                hashMap.put(fir.val, 0);
            }
            fir = fir.next;
        }
        ListNode newhead = new ListNode(0);
        ListNode temp = newhead;
        while (head != null) {
            if (hashMap.get(head.val) == 0) {
                temp.next = head;
                temp = temp.next;
            }
            head = head.next;
        }
        temp.next = null;
        return newhead.next;
    }
}