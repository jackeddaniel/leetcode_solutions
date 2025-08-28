class Solution {
    public:
        void dfs(vector<vector<int>>& adj, vector<bool>& visited, int i) {
            if(visited[i]) return;

            visited[i] = true;

            for(int j = 0; j < adj[i].size(); j++) {
                dfs(adj, visited, adj[i][j]);
            }
            return;
        }
        int makeConnected(int n, vector<vector<int>>& connections) {
            if(connections.size() < n-1) return -1;

            vector<vector<int>> adj(n);

            for(int i = 0; i < connections.size(); i++) {
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }

            vector<bool> visited(n, false);

            int count = 0;

            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    dfs(adj, visited, i);
                    count++;
                }
                
            }


            return count-1;
            
        }
};
