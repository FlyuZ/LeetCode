/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL) {
      return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL) {
      swapNode(temp);
      temp = temp->next;
      if (temp->next != NULL) {
        temp = temp->next;
      } else {
        break;
      }
    }
    return head;
  }
  void swapNode(ListNode *&node) {
    int temp;
    temp = node->val;
    node->val = node->next->val;
    node->next->val = temp;
  }
};
//看题目要求不能直接换值？
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *cur = head->next;
    head->next = swapPairs(head->next->next);
    cur->next = head;
    return cur;
  }
};
