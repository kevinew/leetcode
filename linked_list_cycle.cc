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
        ListNode *p, *q;
        p = head;
        q = head;
        while (p && q) {
            p = p -> next;
            q = q -> next;
            if (NULL == q) return false;
            q = q -> next;
            if (p && q && p == q) return true;
        }
    }
};
