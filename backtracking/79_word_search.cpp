//iterate throught every letter one by one
//and on every letter call the backtracking function and see if it works
//handle edge cases very very carefully



class Solution {
    public:
        bool ans;
        void help(vector<vector<char>> board, string word, int i, int j, int index){
            if(index == word.size()) {
                ans = true;
                return;
            }

            if(board[i][j] != word[i]) {
                return;
            }

            if(board[i][j] == word[i]) {
                board[i][j] = '0';
                
                if(i<word.size() && board[i+1][j] != '0') help(board,word,i++,j,index++);
                if(i>0 && board[i-1][j] != '0') help(board,word,i--,j,index++);
                if(j<word.size() && board[i][j+1] != '0') help(board,word,i,j++,index++);
                if(j>0 && board[i][j-1] != '0') help(board,word,i,j--,index++);
            }
        }
                
                

        bool exist(vector<vector<char>>& board, string word) {
            int l = board.size();
            int w = board[0].size();
            int n = word.size();

            for(int i = 0; i < l; i++) {
                for(int j = 0; j < w; j++) {
                    //call func
                    help(board,word,i,j,0);
                    if(ans == true) return ans;

                }
            }
            return false;
       }
};
