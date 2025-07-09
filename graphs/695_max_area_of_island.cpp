class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int x, int y, int& ans) {
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) return;

            grid[x][y] = 0;
            ans++;
            cout<<ans<<"\n";
            dfs(grid,x+1,y,ans);
            dfs(grid,x-1,y,ans);
            dfs(grid,x,y+1,ans);
            dfs(grid,x,y-1,ans);
        }
            
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            if(grid.empty()) return 0;
            int ans = 0;
            int sub_ans = 0;
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    sub_ans = 0;
                    dfs(grid,i,j,sub_ans);
                    //cout<<sub_ans<<"\n";
                    ans = max(ans, sub_ans);
                }
            }
            return ans;

        }
};
