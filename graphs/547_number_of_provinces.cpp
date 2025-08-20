class Solution {
    public:

        void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
            if(visited[i] == 1) return;

            visited[i] = 1;

            for(int a = 0; a < isConnected[i].size(); a++) {
                if(isConnected[i][a] == 1 && visited[a] == 0) {
                    dfs(isConnected, visited, a);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();

            vector<int> visited(n, 0);

            int province = 0;

            for(int i = 0; i < isConnected.size(); i++ ) {
                if(visited[i] == 1) continue;

                dfs(isConnected, visited, i);
                province++;
            }
            return province;
        }
};
