class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> nextGr;

        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; --i) {
            while(!nextGr.empty() && temperatures[nextGr.top()] <= temperatures[i]) {
                nextGr.pop();
            }

            if(!nextGr.empty()) {
                ans[i] = nextGr.top() - i;
            }

            nextGr.push(i); 
        }

        return ans;
    }
};