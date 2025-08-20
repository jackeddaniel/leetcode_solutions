class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int x, int y) {
            if(x < 0 || x > grid.size()-1 || y < 0 || y > grid[0].size()-1 || grid[x][y] == 0 || grid[x][y] == 2) return;

            grid[x][y] = 2;

            dfs(grid, x-1, y);
            dfs(grid, x+1, y);
            dfs(grid, x, y-1);
            dfs(grid, x, y+1);
        }

        int numEnclaves(vector<vector<int>>& grid) {
            
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if((i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) && grid[i][j] == 1) {
                        dfs(grid, i, j);
                    }
                }
            }

            int count = 0;

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(mat[i][j] == 1) count++;
                }
            }
            return count;
        }
};
