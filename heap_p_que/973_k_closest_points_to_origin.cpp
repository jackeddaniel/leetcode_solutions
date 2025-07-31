class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

            priority_queue<pair<int, vector<int>>> max_heap;

            for(auto& point : points) {
                int x = point[0], y = point[1];
                int dist = x * x + y * y;

                max_heap.push({dist, point});

                if(max_heap.size() > k) {
                    max_heap.pop();
                }
            }

            vector<vector<int>> result;

            while(!max_heap.empty()) {
                result.push_back(max_heap.top().second);
                max_heap.pop();
            }
            return result;
        }
};
