class Solution {
    public: 
        int findDuplicate(vector<int>& nums) {
            vector<int> check(nums.size(), 0);
            
            int dup;
            for (int i : nums) {
                if (check[i] > 0) {
                    dup = i;
                    break;
                }
                check[i] = 1;
            }
            return dup;
        }
};
