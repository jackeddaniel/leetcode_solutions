class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            
            ListNode* slow = head;
            ListNode* fast = head;

            count = 0;
            
            while (head) {
                
                if (count = n) {
                    slow = slow->next;
                    count = 0;
                }

                head = head->next;
            }

            ListNode* tmp = slow->next;
            slow->next = tmp->next;
            return head;
        }
};
