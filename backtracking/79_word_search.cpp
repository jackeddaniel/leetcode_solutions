//iterate throught every letter one by one
//and on every letter call the backtracking function and see if it works
//handle edge cases very very carefully

class Solution {
public:
    void help(bool &ans, vector<vector<char>>& board, string& word, int i, int j, int index) {
        if(ans) return;

        // If all characters matched
        if(index == word.size()) {
            ans = true;
            return;
        }

        // Boundary check
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }

        // Character mismatch
        if(board[i][j] != word[index]) {
            return;
        }

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        // Explore all 4 directions
        help(ans, board, word, i - 1, j, index + 1);
        help(ans, board, word, i + 1, j, index + 1);
        help(ans, board, word, i, j - 1, index + 1);
        help(ans, board, word, i, j + 1, index + 1);

        board[i][j] = temp; // backtrack
    }

    bool exist(vector<vector<char>>& board, string word) {
        int l = board.size();
        int w = board[0].size();
        bool ans = false;

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < w; j++) {
                help(ans, board, word, i, j, 0);
                if(ans) return true;
            }
        }
        return false;
    }
};


