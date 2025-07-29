class Solution {
    public:

        void reorderList(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return;

            ListNode* slow = head;
            ListNode* fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }

            stack<ListNode*> s;
            
            ListNode* tmp = slow->next;
            slow->next = nullptr;
            
            while (tmp != nullptr) {
                s.push(tmp);
                cout<<tmp->val<<" ";
                tmp = tmp->next;
            }

            tmp = head;

            while (!s.empty()) {

                ListNode* tmp2 = tmp->next;
                ListNode* node_from_stack = s.top();
                node_from_stack->next = tmp2;
                s.pop();
                tmp->next = node_from_stack;
                tmp = tmp2;
            }
        }
};





            

            
