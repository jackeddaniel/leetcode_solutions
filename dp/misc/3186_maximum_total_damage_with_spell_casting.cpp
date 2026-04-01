#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long solve(vector<long long>& values, unordered_map<long long, long long>& count, int i, vector<long long>& memo) { 
        if(i > values.size()-1) return 0;
        if(memo[i] != -1) return memo[i];

        long long skip = solve(values, count, i+1, memo);
        
        long long takes = count[values[i]];

        int j = i;

        while(j < values.size() && values[j] <= values[i] + 2) j++;

        takes += solve(values, count, j, memo);

        return memo[i] = max(skip, takes);
    }
        
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,long long> count;

        for(long num : power) count[num] += num;
        vector<long long> values;

        for(auto& key : count) values.push_back(key.first);
        sort(values.begin(), values.end());

        vector<long long>memo(values.size()+1, -1);

        return solve(values, count, 0, memo);
    }
};
