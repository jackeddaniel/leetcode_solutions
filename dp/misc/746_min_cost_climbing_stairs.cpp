#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int bt(vector<int>& cost, int i, vector<int>& memo) {
        if(i >= cost.size()) return 0;
        if(i == cost.size()-1) return memo[i] = cost[i];
        if(memo[i] != -1) return memo[i];

        return memo[i] = cost[i] + min(bt(cost, i+1, memo), bt(cost, i+2, memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        bt(cost, 0, memo);
        return min(memo[0], memo[1]);
    }
};
