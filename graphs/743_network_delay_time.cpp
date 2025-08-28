class Solution {
    public:

        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int>>> a_list(n+1);
            
            for(int i = 0; i < times.size(); i++) {
                a_list[times[i][0]].push_back({times[i][1], times[i][2]});
            }

            vector<int> distance(n+1, INT_MAX);
            vector<int> processed(n+1, 0);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, k});
            distance[k] = 0;

            while(!pq.empty()) {
                int curr = pq.top().second;
                pq.pop();

                if(processed[curr]) continue;
                processed[curr] = 1;

                for(auto edge : a_list[curr]) {
                    int node = edge.first;
                    int weight = edge.second;

                    if(distance[curr] + weight < distance[node]) {
                        distance[node] = distance[curr] + weight;
                        pq.push({distance[node], node});
                    }
                }
            }

            int time = 0;
            
            for(int i = 1; i <= n; i++) {
                if(distance[i] == INT_MAX) return -1;
                time = max(time, distance[i]);
            }

            return time;
        }
};

            




