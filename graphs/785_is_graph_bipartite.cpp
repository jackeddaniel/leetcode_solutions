class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue; 
            
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();

                for (int v : graph[node]) {
                    if (color[v] == color[node]) return false;
                    if (color[v] == -1) {
                        color[v] = 1 - color[node]; 
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};

