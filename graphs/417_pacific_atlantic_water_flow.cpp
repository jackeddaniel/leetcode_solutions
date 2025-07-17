//We need to see if there is a descending order path to pacific ocean and atlantic ocean
//what we can do is maybe iterate through the list and run a dfs


class Solution {
    public:

        void dfs(vector<vector<int>>& heights, int x, int y, int& pac, int& atl) {
            if(x < 0 || x > heights.size()-1 || y < 0 || y > heights[0].size()-1) return;
            if(x == 0 || y == 0) {
                pac = 1;
                return;
            }
            if(x == heights.size()-1 || y == heights[0].size()-1) {
                atl = 1;
                return;
            }
    
            if(heights[x][y] >= heights[x-1][y]) dfs(heights,x-1,y,pac,atl);
            if(heights[x][y] >= heights[x+1][y]) dfs(heights,x+1,y,pac,atl);
            if(heights[x][y] >= heights[x][y-1]) dfs(heights,x,y-1,pac,atl);
            if(heights[x][y] >= heights[x][y+1]) dfs(heights,x,y+1,pac,atl);

            return;
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int pac;
            int atl;
            int m = heights.size();
            int n = heights[0].size();
            vector<vector<int>> check(m,vector<int>(n,0));
            vector<vector<int>> res;
            vector<int> tmp;
            for(int i = 0; i < heights.size(); i++) {
                for(int j = 0; j < heights[0].size(); j++) {
                    pac = 0;
                    atl = 0;
                    dfs(heights,i,j,pac,atl);
                    if(i == 0 && j == 4) {
                        cout<<pac<< " "<<atl<<"\n";
                    }
                    if(pac == 1 && atl == 1) {
                        tmp.push_back(i);
                        tmp.push_back(j);
                        res.push_back(tmp);
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                }
                
            }
            return res;

        }
};
