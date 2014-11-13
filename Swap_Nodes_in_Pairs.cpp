//It's very difficult to be bug-free.

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
        if (head == NULL)
            return NULL;

        ListNode *ans = NULL;
        ListNode *ansHead = NULL;

        if (head->next == NULL)
            return head;

        ansHead = head->next;
        ans = head->next;

        ListNode *a = head;
        ListNode *b = head->next;
        head = head->next->next;

        ans->next = a;
        ans = ans->next;

        while (head != NULL)
        {
            ListNode *a = head;

            if (head->next == NULL)
            {
                ans->next = a;
                //Note that to move ans
                ans = ans->next;
                break;
            }

            ListNode *b = head->next;
            head = head->next->next;

            ans->next = b;
            ans = ans->next;
            ans->next = a;
            //Note that to move ans
            ans = ans->next;
        }

        //Note that to link the NULL to the end
        ans->next = NULL;

        return ansHead;
    }
};

