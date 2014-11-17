//In fact, it is the select sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return NULL;

        //We can only claim and init source by the initial function
        ListNode source(INT_MIN);
        source.next = head;

        ListNode *i = &source;
        while (i->next != NULL)
        {
            ListNode *j = i->next;
            while (j != NULL && j->next !=NULL)
            {
                if (i->next->val > j->next->val)
                {
                    ListNode *a = i->next, *b = j->next->next;
                    i->next = j->next;
                    j->next->next = a;
                    j->next = b;
                }
                //Note that j may be moved forward after the swap.
                //So if we move j after the swap, we will skip one node.
                else j = j->next;
            }
            i = i->next;
        }
        return source.next;
    }
};

