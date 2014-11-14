//Very tricky.
//Calculate...

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;

        ListNode *p, *q;
        p = head;
        q = head;

        while (p != NULL && q != NULL)
        {
            p = p->next;
            if (q->next == NULL)
                return NULL;
            else
                q = q->next->next;
            if (p == q)
            {
                ListNode *pp = head;
                while (pp != p)
                {
                    pp = pp->next;
                    p = p->next;
                }
                return pp;
            }
        }

        return NULL;
    }
};

