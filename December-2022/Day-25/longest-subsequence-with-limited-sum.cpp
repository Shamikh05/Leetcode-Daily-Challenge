class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size(), n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i=0; i<m; ++i) {
            int target = queries[i];
            int sum = 0;
            int len = 0;

            for(int j=0; j<n; ++j) {
                if((sum + nums[j]) > target) {
                    break;
                }

                ++len;
                sum += nums[j];
            }

            ans.push_back(len);
        }

        return ans;
    }
};