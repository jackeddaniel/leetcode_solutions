class Solution {
    public:
        bool help(vector<int>& piles, int mid,int h) {
            int time = 0;
            for(int i = 0; i < piles.size(); i++) {
                time += (piles[i] + mid - 1)/mid;
                if(time > h) return false;
            }
            return true;
        }
                
        int minEatingSpeed(vector<int>& piles, int h) {
            int max = *max_element(piles.begin(), piles.end());
            int min = 1;
            
            int ans = max;

            while(min<=max) {
                int mid = min + (max-min)/2;
                
                if(help(piles,mid,h)) {
                    ans = mid;
                    max = mid - 1;
                } else {
                    min = mid + 1;
                }
            }

                return ans;
        }
};
