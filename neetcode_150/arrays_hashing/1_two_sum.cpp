#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checker;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(checker.find(diff) != checker.end()) {
                res.push_back(nums[i]);
                res.push_back(checker[diff]);
                break;
            }
            checker[nums[i]] = i;
        }
       return res; 
    }
};
