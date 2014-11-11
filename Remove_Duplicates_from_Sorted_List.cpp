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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *now = head, *next;

        if (head == NULL)
            return head;

        next = head->next;

        while (next != NULL)
        {
            if (now->val != next->val)
            {
                now->next = next;
                now = now->next;
            }

            next = next->next;
            //Note that special judge
            if (next == NULL)
                now->next = NULL;
        }
        return head;
    }
};
