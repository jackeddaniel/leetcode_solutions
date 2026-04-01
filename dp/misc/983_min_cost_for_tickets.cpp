#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& memo) {
        if(i >= days.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int j = i;

        while(j < days.size() && days[j] <= days[i] + 6) {
            j++;
        }
        int seven = j;

        j = i;

        while(j < days.size() && days[j] <= days[i] + 29) {
            j++;
        }
        int thirty = j;

        int one_day = costs[0] + solve(days, costs, i+1, memo);
        int seven_day = costs[1] + solve(days, costs, seven, memo);
        int thirty_day = costs[2] + solve(days, costs, thirty, memo);

        return memo[i] = min(one_day, min(seven_day, thirty_day));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);

        return solve(days, costs, 0, memo);
    }
};
