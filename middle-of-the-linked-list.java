/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        if (head.next == null)
            return head;
        ListNode fir = head;
        ListNode sec = head;
        while (sec.next != null) {
            fir = fir.next;
            sec = sec.next;
            if (sec.next == null) {
                return fir;
            } else
                sec = sec.next;
        }
        return fir;
    }
}