#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_map>
#include<deque>
#include<climits>
#include<iostream>
#include<numeric>
#include<unordered_set>



using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        vector<int> res;
        int n = nums.size();
        if(n == 0) return res;
        
        deque<int> check;

        for(int i = 0; i < n; i++) {
            while(!check.empty() && check.front() <= i-k) check.pop_front();

            while(!check.empty() && nums[check.back()] < nums[i]) check.pop_back();

            check.push_back(i);

            if(i >= k-1) res.push_back(check.front());
        }
        return res; 
    }
};

int main() {
}

