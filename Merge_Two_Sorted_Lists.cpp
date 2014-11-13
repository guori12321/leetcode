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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //*head, rather than head
        ListNode * ans = NULL, *head = NULL;

        if (l1 == NULL && l2 == NULL)
            return NULL;
        //Consider all the initial environment
        //Consider weather the variable you want to use is assigned already
        if (l1 == NULL)
        {
            ans = l2;
            l2 = l2->next;
        }
        else
            if (l2 == NULL)
            {
                ans = l1;
                l1 = l1->next;
            }
            else
                if (l1->val < l2->val)
                {
                    ans = l1;
                    l1 = l1->next;
                }
                else
                {
                    ans = l2;
                    l2 = l2->next;
                }

        head = ans;

        while ( l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l2 != NULL)
                if (l1-> val < l2->val )
                {
                    ans->next = l1;
                    ans = ans->next;
                    l1 = l1->next;
                }
                else
                {
                    ans->next = l2;
                    ans = ans->next;
                    l2 = l2->next;
                }
            if (l1 == NULL)
                while (l2 != NULL)
                {
                    ans->next = l2;
                    ans = ans->next;
                    l2 = l2->next;
                }
            if (l2 == NULL)
                while (l1 != NULL)
                {
                    ans->next = l1;
                    ans = ans->next;
                    l1 = l1->next;
                }
        }
        //Remember to return ans;
        //In this case return head, rather than the most popular variable "ans"
        return head;
    }
};
