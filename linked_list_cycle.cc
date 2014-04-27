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
    bool hasCycle(ListNode *head) {
      if (NULL == head) return false;
      ListNode *slow, *fast;
      slow = head;
      fast = head;
      while (slow && fast) {
        slow = slow -> next;
        fast = fast -> next;
        if (NULL == fast) return false;
        fast = fast -> next;
        if (slow && fast && slow == fast) return true;
      }
    }
};
