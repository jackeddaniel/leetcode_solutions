class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();

            vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

            queue<pair<int,int>> q;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < j++) {
                    if(mat[i][j] == 0) {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }

            vector<int> dirs = {0, 1, 0, -1, 0};

            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dirs[k];
                    int ny = y + dirs[k+1];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if(dist[nx][ny] > dist[x][y] + 1) {
                            dist[nx][ny] = dist[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            return dist;
        }
};
