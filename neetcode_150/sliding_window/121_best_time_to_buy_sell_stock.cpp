#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        int l = 0;
        int r = 1;

        int prof = 0;

        while (r < size) {
            if(prices[l] < prices[r]) {
                prof = max(prof, prices[r] - prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return prof;
    }
};
