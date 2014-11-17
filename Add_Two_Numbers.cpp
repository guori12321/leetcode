//It is necessary to add the virtual head node.
//Because we can only conduct l1->next, rather than l1. If we do not have the virtual head node, we need to have specific judgement weather the carry is for l1 or l1->next.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head1(-1);
        head1.next = l1;

        l1 = &head1;

        int carry = 0;

        while (l1->next != NULL)
        {
            int a = l1->next->val;
            int b = 0;
            if (l2 != NULL)
            {
                b = l2->val;
                l2 = l2->next;
            }

            l1->next->val = a + b + carry;
            carry = l1->next->val /10;
            l1->next->val %= 10;

            l1 = l1->next;
        }

        if (l2 != NULL)
            l1->next = l2;

        while (l1->next != NULL)
        {
            l1->next->val += carry;
            carry = l1->next->val / 10;
            l1->next->val %= 10;

            l1 = l1->next;
        }

        if (carry > 0)
            l1->next = new ListNode(carry);

        return head1.next;
    }
};

