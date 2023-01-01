class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prevToPrevDp(2, 0), prevDp(2, 0), currDp(2, 0);
        
        for(int i=n-1; i>=0; --i) {
            currDp[1] = max(prevDp[0] - prices[i], prevDp[1]);
            currDp[0] = max(prevToPrevDp[1] + prices[i], prevDp[0]);
            prevToPrevDp = prevDp;
            prevDp = currDp;
        }

        return currDp[1];
    }
};