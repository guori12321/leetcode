//Very tricky question.
//As to detect weather there is a cycle in a list, we claim two pointers. p = head, q = head
//And let q move n steps first, and then p move one step and q one, when q == NULL, p->next is what we want to delete.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;

        //It is the initial function of the ListNode
        //ListNode(int x) : val(x), next(NULL) {}
        ListNode start(-1);
        start.next = head;
        p = &start;
        q = &start;

        for (int i = 0; i < n; i++)
            q = q->next;

        //Attention q or q->next
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        ListNode *t = p->next;
        p->next = p->next->next;
        delete t;

        return start.next;
    }
};

