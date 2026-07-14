#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        set<int> checker;
        for(int num : nums) {
            if(checker.count(num)) return true;
            checker.insert(num);
        }
        return false;
    }
};
