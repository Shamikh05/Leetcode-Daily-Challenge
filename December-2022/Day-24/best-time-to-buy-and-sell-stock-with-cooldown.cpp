class Solution {
private:
    int compute(int idx, bool buy, vector<int> &prices, int n, vector<vector<int> > &dp) {
        // No more days to trade, return 0.
        if(idx >= n) {
            return 0;
        }

        // If already computed, return the value.
        if(dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        // Dont trade today, move to next day.
        int notTrade = compute(idx+1, buy, prices, n, dp);
        // Trade today.
        int trade = 0;

        // If you are not holding any stock, buy the current stock and move to the next day.
        // Else if you are holding a stock, sell it and move to the next to next day (skip cooldown day).
        if(buy) {
            trade = compute(idx+1, false, prices, n, dp) - prices[idx];
        } else {
            trade = compute(idx+2, true, prices, n, dp) + prices[idx];
        }

        // Return the maximum of rseults from the given 2 options (trade or not trade).
        return dp[idx][buy] = max(trade, notTrade);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2, -1));
        return compute(0, true, prices, n, dp);
    }
};