class Solution {
    public:
        int maxProfit(vector<int>& prices) {

            int prof = 0;
            int sp = prices[prices.size()-1];

            for (int i = prices.size()-1; i > -1; i--) {
                if (prices[i] > sp) sp = prices[i];

                prof = max(prof, sp-prices[i]);
            }

            return prof;
        }
};
