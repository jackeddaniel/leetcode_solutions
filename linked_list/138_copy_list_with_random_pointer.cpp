// We need to make a deep copy
// We will first make a simple deep copy
// While doing this, we will have a hashmap of uncopied nodes, to copied nodes
// And with the help of that hash we will make deep copy
//

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == nullptr) return nullptr;

            Node* copy = new Node(head->val);
            Node* curr = copy;

            Node* original = head->next;

            unordered_map<Node*, Node*> hash;
            hash[head] = copy;

            while (original) {
                curr->next = new Node(original->val);
                hash[original] = curr->next;
                curr = curr->next;
                original = original->next;
            }
            
            curr = copy;
            original = head;

            while (original && curr) {
                if (original->random) {
                    curr->random = hash[original->random];
                }
                original = original->next;
                curr = curr->next;
            }

            return copy;
        }
};
