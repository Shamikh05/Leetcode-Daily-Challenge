class Solution {
private:
    bool compute(int idx, int n, vector<int> &nums, vector<int> &dp) {
        if(idx >= (n-1)) {
            return true;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        for(int i=1; i<=nums[idx]; ++i) {
            bool res = compute(idx+i, n, nums, dp);
            if(res == true) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return compute(0, n, nums, dp);
    }
};