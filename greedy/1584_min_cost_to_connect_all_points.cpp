class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {

            vector<vector<pair<int, int>>> adj(points.size());

            for(int i = 0; i < points.size(); i++) {
                for(int j = 0; j < points.size(); j++) {
                    
                    if(i == j) continue;
                    
                    int v = j; 
                    int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                    adj[i].push_back({v, w});
                }
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            vector<bool> in_tree(points.size(), false);
            

            pq.push({0, 0});
            int cost = 0;

            while(!pq.empty()) {
                auto [w, u] = pq.top();
                pq.pop();

                if(in_tree[u]) continue;

                in_tree[u] = true;
                cost += w;

                for(auto[v, wt] : adj[u]) {
                    if(!in_tree[v]) pq.push({wt, v});
                }
            }

            return cost;

        }
};

