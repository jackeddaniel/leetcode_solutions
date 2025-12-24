class Solution {
    public:
        int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
            if(x == grid.size()-1 && y == grid[0].size()-1) return 1;

            if(dp[x][y] != -1) return dp[x][y];

            int right = 0;
            int down = 0;

            if(x < grid.size()-1 && y < grid[0].size() && grid[x+1][y] != 1) down += solve(x+1, y, grid, dp);
            if(y < grid[0].size()-1 && x < grid.size() && grid[x][y+1] != 1) right += solve(x, y+1, grid, dp);

            return dp[x][y] = down + right;
        }

        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if(obstacleGrid[0][0] == 1) return 0;
            if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0] == 0) return 1;
            if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0] == 1) return 0;
            vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

            solve(0, 0, obstacleGrid, dp);

            return dp[0][0];
        }
};
