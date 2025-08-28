class Solution {
    public:
        void dfs(vector<vector<int>>& heights, int x, int y, int local, int& minimum) {
            if(x == heights.size()-1 && y == heights.size()-1) {
                minimum = min(local, minimum);
                return;
            }

            if(x > heights.size()-1 || y > heights.size()-1) return;

            if(x > 0) dfs(heights, x-1, y, local + (heights[x-1][y] - heights[x][y]), minimum);
            if(x < heights.size()-1) dfs(heights, x+1, y, local + (heights[x+1][y] - heights[x][y]), minimum);
            if(y > 0) dfs(heights, x, y-1, local + (heights[x][y-1] - heights[x][y]), minimum);
            if(y < heights.size()-1) dfs(heights, x, y+1, local + (heights[x][y+1] - heights[x][y]), minimum);

        }

        int minimumEffortPath(vector<vector<int>>& heights) {
            int minimum = INT_MAX;

            dfs(heights, 0, 0, 0, minimum);
            
            return minimum;
        }
};
