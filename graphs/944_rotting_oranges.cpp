//multi-source bfs

class Solution {
    public: 
        int orangesRotting(vector<vector<int>>& grid) {
            int n = 0;
            queue<pair<int,int>> q;

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == 0) continue;
                    if(grid[i][j] == 1) n++;
                    if(grid[i][j] == 2) q.push({i,j});
                }
            }
            if(n == 0) return 0;

            int mins = 0;

            while(!q.empty()) {

                int size = q.size();

                for(int i = 0; i < size(); i++) {
                    int a = q.front().left;
                    int b = q.front().right;

                    q.pop();
                    
                    if(i<grid.size()-1;i




        }
};
