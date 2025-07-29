class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res = new ListNode(0);  
        ListNode* curr = res;

        ListNode* it1 = l1;
        ListNode* it2 = l2;

        int carry = 0;

        while (it1 || it2) {
            int sum = carry;

            if (it1 && it2) {
                sum += it1->val + it2->val;
                it1 = it1->next;
                it2 = it2->next;
            } else if (it1) {
                sum += it1->val;
                it1 = it1->next;
            } else if (it2) {
                sum += it2->val;
                it2 = it2->next;
            }

            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            curr->next = new_node;
            curr = curr->next;
        }

        if (carry > 0) {
            ListNode* new_node = new ListNode(carry);
            curr->next = new_node;
        }

        return res->next;
    }
};

