class Solution {
private:
    bool isSorted(string &col, int &n) {
        for(int i=1; i<n; ++i) {
            if(col[i] < col[i-1]) {
                return false;    
            }
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();

        int i = 0, ans = 0;
        while(i < m) {
            string col = "";
            for(string str : strs) {
                col += str[i];
            }

            bool sorted = isSorted(col, n);
            if(sorted == false) {
                ++ans;
            }

            ++i;
        }

        return ans;
    }
};