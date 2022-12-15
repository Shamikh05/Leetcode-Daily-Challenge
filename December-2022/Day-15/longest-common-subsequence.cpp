class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prevDp(n2+1, 0), currDp(n2+1, 0);

        for(int i=1; i<=n1; ++i) {
            for(int j=1; j<=n2; ++j) {
                currDp[j] = (text1[i-1] == text2[j-1]) ? (1 + prevDp[j-1]) : max(prevDp[j], currDp[j-1]);
            }
            prevDp = currDp;
        }

        return prevDp[n2];
    }
};