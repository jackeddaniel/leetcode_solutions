class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, -1);
            nums.insert(nums.end(), nums.begin(), nums.end());
            
            stack<int> s;

            for(int i = 0; i < nums.size(); i++) {
                while(!s.empty() && nums[i] > nums[s.top()]) {
                    if(s.top() < n) {
                        res[s.top()] = nums[i];
                    }
                    s.pop();
                }
                s.push(i);
            }

            return res;
        }
};
