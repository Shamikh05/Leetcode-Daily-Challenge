class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Map to store freuency of each unique number.
        unordered_map<int, int> freq;

        // Store the frequency of each unique number in freq map.
        for(int task : tasks) {
            ++freq[task];
        }

        int ans = 0;
        // Loop over the freq map to compute the min. rounds for each frequency.
        for(auto it : freq) {
            int currFreq = it.second;

            // If freq is 1, then that task cannot be completed, return -1.
            if(currFreq == 1) {
                return -1;
            }
            
            // Get the quotient and remainder of the current freuency divided by 3.
            int quot = currFreq/3;
            int rem = currFreq % 3;

            // Take sum of all the unique tasks rounds in answer.
            if(rem == 0) {
                ans += quot;
            } else {
                ans += quot + 1;
            }
        }

        return ans;
    }
};