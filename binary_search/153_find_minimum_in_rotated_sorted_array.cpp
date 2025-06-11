class Solution {
    public:
        int findMin(vector<int>& nums) {
            int begin = 0;
            int end = nums.size()-1;

            if(nums[begin] < nums[end]) return nums[begin];
            int ans = INT_MAX;
            while(begin <= end) {
                int mid = begin + (end-begin)/2;
                ans = min(nums[mid],ans);
                if(nums[mid]>= nums[end]) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};
