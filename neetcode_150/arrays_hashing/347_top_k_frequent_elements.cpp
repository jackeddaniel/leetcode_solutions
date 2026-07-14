#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        for(int num : nums) {
            counter[num]++;
        }

        vector<pair<int,int>> helper_vector(counter.begin(), counter.end());

        sort(helper_vector.begin(), helper_vector.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
                });

        vector<int> res;

        for(auto& it : helper_vector) {
            if(k == 0) break; 
            res.push_back(it.first);
            k--;
        }
        return res; 
    }
};
