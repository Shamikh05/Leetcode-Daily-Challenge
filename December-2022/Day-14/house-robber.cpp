class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // If there is only 1 house present, rob that house to take all the available money (Edge Case).
        if(n == 1) {
            return nums[0];
        }
        
        // Instead of taking DP array, take 2 variables to store (i-1)th and (i-2)th DP state.
        int prevDp = nums[0];
        int currDp = max(nums[0], nums[1]);

        // Loop upto n houses and compute maximum money using both the DP states.
        for(int i=2; i<n; ++i) {
            // Consider both the cases (to rob or to leave). 
            int rob = prevDp + nums[i];
            int notRob = currDp;
            // Get the maximum money after considering both the above cases.
            int maxMoney = max(rob, notRob);

            // Set previous DP and current DP state for computing maxMoney for next iteration.
            prevDp = currDp;
            currDp = maxMoney;
        }

        // Return the latest DP state.
        return currDp;
    }
};