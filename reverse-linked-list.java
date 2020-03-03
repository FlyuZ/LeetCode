/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode cur = head.next;
        ListNode tmp = head;
        ListNode next = head.next.next;
        head.next = null;
        while (true) {
            cur.next = tmp;
            tmp = cur;
            cur = next;
            if (cur == null)
                break;
            next = next.next;
        }
        return tmp;
    }
}