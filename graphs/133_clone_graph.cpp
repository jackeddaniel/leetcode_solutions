//so what I have to do is deep copy of a tree
//what I will do is perform a dfs on the graph and creat new nodes using new and structure them as present in the graph

class Solution {
    public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>& visited) {
        if(!node) return nullptr;

        if(visited.count(node)) {
            return visited[node];
        }

        Node* copy = new Node(node->val);
        visited[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, visited));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> visited;

        return dfs(node,visited);
    }
};
        

        

