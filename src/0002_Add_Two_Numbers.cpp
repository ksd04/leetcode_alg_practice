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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode *p1, *p2, *p3;
        int i1, i2, i3;
        int carry, remainder;
        int is_empty;

        p1 = l1;
        p2 = l2;
        carry = 0;
        is_empty = 1;

        while (p1 != NULL || p2 != NULL || carry != 0){
            if (p1 != NULL){
                i1 = p1->val;
                p1 = p1->next;
            }
            else
                i1 = 0;

            if (p2 != NULL){
                i2 = p2->val;
                p2 = p2->next;
            }
            else
                i2 = 0;
            
            i3 = i1 + i2 + carry;
            carry = i3 / 10;
            remainder = i3 % 10;

            if(is_empty){
                p3 = new ListNode(remainder);
                result = p3;
                is_empty = 0;
            }
            else
            {
                p3->next = new ListNode(remainder);
                p3 = p3->next;
            }
        }

        return result;
    }
};
