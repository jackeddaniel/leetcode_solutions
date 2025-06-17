class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int begin = 0;
            int end = nums.size()-1;
            
            while(begin <= end) {

                int mid = begin + (end-begin)/2;

                if(nums[begin] == target) return begin;
                if(nums[end] == target) return end;
                if(nums[mid] == target) return mid;

                if(nums[mid] < target) {
                    if(nums[end] < target && nums[mid] < nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else {
                    if(nums[begin] > target && nums[mid] > nums[end]) {
                        begin = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
            return -1;

        }
           
};
