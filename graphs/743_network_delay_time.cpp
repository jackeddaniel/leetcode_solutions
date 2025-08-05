class Solution {
    public:

        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // build an adjacency list
            vector<vector<pair<int,int>>> adj_list(n+1);
            for(auto t : times) {
                adj_list[t[0]].push_back({t[1],t[2]});
            }
            
            // initiliaze the distance and processed arrays
            vector<int> distance(n+1);
            for(int i = 0; i <= n; i++) distance[n] = INT_MAX;
            vector<int> processed(n+1);
            for(int i = 0 i <= n; i++) processed[n] = INT_MAX;

            distance[k] = 0;

            // make the min_heap
            priority_queue<pair<int,int>, vector<pair<int,int>>, greate<pair<int,int>>> pq;

            pq.push({0,k});

            while(!pq.empty()) {
                int curr = pq.top().second;
                pq.pop();

                if(processed[curr] == 1) continue;

                processed[curr] = 1;

                for(auto edge : adj_list[curr]) {
                    int node = edge.first;
                    int weight = edge.second;

                    int new_weight = distance[curr] + weight;

                    if(new_weight < distance[node]) {
                        distance[node] = new_weight;
                        pq.push({distance[node], node});
                    }
                }
            }

            int ans = 0;
            for(int i = 1; i <= n; i++) {
                if(distance[i] == INT_MAX) return -1;
                ans = max(ans, distance[i]);
            }
            return ans;
        }
};

            




