class Solution {
    public:
        void dfs(vector<vector<char>>& board, vector<vector<char>>& grid, int x, int y) {
            if(x < 0 || x > board.size()-1 || y < 0 || y > board[0].size()-1 || grid[x][y] == 'O') {
                cout<<"returning from dfs"<<"\n";
                return;
            }
            grid[x][y] = 'O';
            
            if(x > 0 && board[x-1][y] == 'O') {
                cout<<"going up"<<"\n";
                dfs(board,grid, x-1,y);
            }
            if(x < board.size()-1 && board[x+1][y] == 'O') {
                cout<<"going down"<<"\n";
                dfs(board,grid,x+1,y);
            }
            if(y > 0 && board[x][y-1] == 'O') {
                cout<<"going  left"<<"\n";
                dfs(board,grid,x,y-1);
            }
            if(y < board[0].size()-1 && board[x][y+1] == 'O') {
                cout<<"going right"<<"\n";
                dfs(board,grid,x,y+1);
            }
        }

        void solve(vector<vector<char>>& board) {
            int m = board.size();
            int n = board[0].size();

            vector<vector<char>> grid(m, vector<char>(n, 'X'));

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                        cout<<"called dfs"<<"\n";
                        dfs(board,grid,i,j);
                        
                    }
                    cout<<i<<" "<<j<<"\n";
                    cout<<"did not call dfs"<<"\n";
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 'O' && grid[i][j] == 'X') board[i][j] = 'X';
                }
            }
        }
};

