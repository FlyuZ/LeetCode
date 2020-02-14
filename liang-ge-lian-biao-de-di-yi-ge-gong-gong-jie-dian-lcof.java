/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        while (nodeA != nodeB) {
            if (nodeA == null)
                nodeA = headB;
            else
                nodeA = nodeA.next;
            if (nodeB == null)
                nodeB = headA;
            else
                nodeB = nodeB.next;
        }
        return nodeA;
    }
}