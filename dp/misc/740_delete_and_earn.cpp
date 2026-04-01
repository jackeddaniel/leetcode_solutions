#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int solve(vector<int>& values, unordered_map<int,int>& mp, int i, vector<int>& memo) {
        if(i < 0) return 0;
        if(memo[i] != -1) return memo[i];

        // option 1: skip current
        int skip = solve(values, mp, i - 1, memo);

        // option 2: take current
        int take = mp[values[i]];

        if(i > 0 && values[i] == values[i-1] + 1) {
            take += solve(values, mp, i - 2, memo);
        } else {
            take += solve(values, mp, i - 1, memo);
        }

        return memo[i] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums) mp[x] += x;

        vector<int> values;
        for(auto &p : mp) values.push_back(p.first);
        sort(values.begin(), values.end());

        vector<int> memo(values.size()+1, -1);

        return solve(values, mp, values.size() - 1, memo);
    }
};
