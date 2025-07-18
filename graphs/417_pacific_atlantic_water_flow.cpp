// Basically run two dfs, one to pacific ocean and one two atlantic ocean
// We need to keep a check grid 
// We are using versions to avoid re-initialzing the grid again and again to 0 or any other number





class Solution {
    public:
        void pac_dfs(vector<vector<int>>& heights, vector<vector<int>>& check, int version, int x, int y, int& pac) {
            if(x < 0 || x > heights.size()-1 || y < 0 || y > heights[0].size()-1 || check[x][y] == version) return;

            if(x == 0 || y == 0) {
                pac = 1;
                check[x][y] = version;
                return;
            }

            check[x][y] = version;
            if(x > 0 && heights[x-1][y] <= heights[x][y]) pac_dfs(heights,check,version,x-1,y,pac);
            if(x < heights.size()-1 && heights[x+1][y] <= heights[x][y]) pac_dfs(heights,check,version,x+1,y,pac);
            if(y > 0 && heights[x][y-1] <= heights[x][y]) pac_dfs(heights,check,version,x,y-1,pac);
            if(y < heights[0].size()-1 && heights[x][y+1] <= heights[x][y]) pac_dfs(heights,check,version,x,y+1,pac);
            
            return;
        }
            
        void atl_dfs(vector<vector<int>>& heights, vector<vector<int>>& check, int version, int x, int y, int& atl) {
            if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || check[x][y] == version) return;

            if (x == heights.size() - 1 || y == heights[0].size() - 1) {
                atl = 1;
                check[x][y] = version;
                return;
            }

            check[x][y] = version;

            if (x > 0 && heights[x-1][y] <= heights[x][y]) atl_dfs(heights, check, version, x-1, y, atl);
            if (x < heights.size() - 1 && heights[x+1][y] <= heights[x][y]) atl_dfs(heights, check, version, x+1, y, atl);
            if (y > 0 && heights[x][y-1] <= heights[x][y]) atl_dfs(heights, check, version, x, y-1, atl);
            if (y < heights[0].size() - 1 && heights[x][y+1] <= heights[x][y]) atl_dfs(heights, check, version, x, y+1, atl);

            return;
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int m = heights.size();
            int n = heights[0].size();

            int pac;
            int atl;
            int version = 1;

            vector<vector<int>> check(m, vector<int>(n, 0));

            vector<vector<int>> res;
            for(int i = 0; i < heights.size(); i++) {
                for(int j = 0; j < heights[0].size(); j++) {
                    pac = 0;
                    atl = 0;

                    version++;
                    pac_dfs(heights,check,version,i,j,pac);

                    version++;
                    atl_dfs(heights,check,version,i,j,atl);

                    if(pac == 1 && atl == 1) {
                        res.push_back({i,j});
                    }
                }
            }
            return res;
        }
};
