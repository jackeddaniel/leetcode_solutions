class Solution {
    public:
        int atmost(vector<int>& nums, int k){
            int l = 0;
            int total = 0;
            int odd = 0;

            for(int r = 0; r < nums.size(); r++) {
                if(nums[r] % 2 != 0) odd++;

                while(odd > k) {
                    if(nums[l] % 2 != 0) {
                        odd--;
                        l++;
                    } else {
                        l++;
                    }
                }

                total += (r - l + 1);
            }
            return total;
        }
                
        int numberOfSubarrays(vector<int>& nums, int k) {
            return atmost(nums, k) - atmost(nums, k - 1);
        }
};
