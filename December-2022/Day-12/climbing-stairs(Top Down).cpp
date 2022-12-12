class Solution {
private:
    int compute(int n, vector<int> &dp) {
        if(n==0 || n==1) {
            return 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int arriveFromLastStep = compute(n-1, dp);
        int arriveFromSecondLastStep = compute(n-2, dp);
        
        return dp[n] = arriveFromLastStep + arriveFromSecondLastStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return compute(n, dp);
    }
};