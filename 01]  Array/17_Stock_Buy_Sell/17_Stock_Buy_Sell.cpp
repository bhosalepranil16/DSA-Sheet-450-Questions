class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) {
            return 0;
        } else if(n == 2) {
            if(prices[1] - prices[0] > 0) {
                return prices[1] - prices[0];
            } else {
                return 0;
            }
        } else {
            int minValue = prices[0];
            int res = INT_MIN;
            for(int i=1;i<n;i++) {
                minValue = min(minValue, prices[i-1]);
                res = max(res, prices[i] - minValue);
            }
            if(res < 0) {
                return 0;
            } else {
                return res;
            }
        }
    }
};