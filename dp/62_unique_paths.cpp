class Solution {
    public:
        int solve(int m, int n, int x, int y, vector<vector<int>>& dp){
            if(x == m-1 && y == n-1) return 1;

            if(dp[x][y] != -1) return dp[x][y];

            int left = 0;
            int down = 0;

            if(x < m-1 && y < n) left += solve(m, n, x+1, y,dp);
            if(y < n-1 && x < m) down += solve(m, n, x, y+1,dp); 

            return dp[x][y] = left+down;
        }
        int uniquePaths(int m, int n) {
            if(m == 1 && n == 1) return 1;
            vector<vector<int>> dp(m, vector<int>(n, -1));
            solve(m,n,0,0,dp);

            return dp[0][0];

        }
};
