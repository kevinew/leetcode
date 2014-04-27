/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 先用快慢下标游走方法，找到在环中重合的节点，再在此节点处打断环，那么就形成了两个单链表，这就成了寻找两个单链表相交首节点的问题了。
// code以后再完善。

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
/*
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
    */
};
