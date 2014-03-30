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
    void reorderList(ListNode *head) {
        ListNode *p = head;
        while (NULL != p && NULL != p->next) {
            reorderNode(p);
            p = p->next;
            if (!p) break;
            p = p->next;
        }
    }
    
    void reorderNode(ListNode *head) {
        if (NULL == head || NULL == head->next) return;
        ListNode *p1, *p2;
        // p2 p1 travel the list.
        p1 = head;
        while (NULL != p1->next) {
            p2 = p1;
            p1 = p1->next;
        }
        p2->next = NULL;
        p1->next = head->next;
        head->next = p1;
    }
};
