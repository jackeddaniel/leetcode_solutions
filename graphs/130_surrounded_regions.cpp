class Solution {
    public:
        void dfs(vector<vector<char>>& board, vector<vector<int>>& check, int x, int y) {
            if(x < 0 || x > board.size()-1 || y < 0 || y > board[0].size()-1 || board[x][y] == 'X' || check[x][y] == 1) return;

            check[x][y] = 1;

            if(x > 0) dfs(board,check,x,y);
            if(x < 


        void solve(vector<vector<char>>& board) {
            int m = board.size();
            int n = board[0].size();

            vector<vector<int>> check(m, vector<int>(n, 0));

            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {
                    if(i != 0 || i != m-1 || j != 0 || j != n-1 || board[i][j] == 'X') continue;

                    dfs(board, check, i, j);
                }
            }
            
            
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {

                    if(board[i][j] == '0' && check[i][j] == 0) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};
