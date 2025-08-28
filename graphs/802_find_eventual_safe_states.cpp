class Solution {
    public:

        bool dfs(vector<vector<int>>& graph, int i) {
            if(visited[i] == 1) return false;
            if(visited[i] == 2) return true;
            
            visit[i] = 1;

            for(int next : graph[i]) {
                if(!dfs(graph, next, visited)) return false;
            }
            
            visit[i] = 2;
            return true;
        }

        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int> res;
            vector<int> visited(graph.size(), 0);

            for(int i = 0; i < graph.size(); i++) {
                if(dfs(graph, i)) {
                        res.push_back(i);
                }
                for(int a = 0; a < visited.size(); a++) {
                    visited[a] = 0;
                }
            }


            sort(res.begin(), res.end());
            return res;


        }
};
