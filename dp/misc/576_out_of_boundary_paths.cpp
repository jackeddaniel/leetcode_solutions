#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long solve(int m, int n, int moves, int x, int y,vector<vector<vector<long long>>>& memo) {
        if(x < 0 || x >= m) return 1;
        if(y < 0 || y >= n) return 1;
        if(moves == 0) return 0;
        if(memo[moves][x][y] != -1) return memo[moves][x][y];

        long up = solve(m, n, moves-1, x-1, y,memo)%MOD;
        long down = solve(m, n, moves-1, x+1, y,memo)%MOD;
        long left = solve(m, n, moves-1, x, y-1,memo)%MOD;
        long right = solve(m, n, moves-1, x, y+1,memo)%MOD;

        return memo[moves][x][y] = (up+down+left+right)%MOD;
   }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> memo(maxMove+1, vector<vector<long long>>(m+1, vector<long long>(n+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn,memo);
    }
};
