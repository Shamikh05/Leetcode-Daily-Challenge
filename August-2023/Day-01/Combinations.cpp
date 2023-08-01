class Solution {
private:
    vector<vector<int> > ans;

    void populateCombinations(int num, int n, int k, vector<int> &temp) {
        // Base condition
        if(k == 0) {
            ans.push_back(temp);
            return;
        }

        if(num > n) {
            return;
        }

        // Don't take num
        populateCombinations(num+1, n, k, temp);

        // Take num
        temp.push_back(num);
        populateCombinations(num+1, n, k-1, temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        populateCombinations(1, n, k, temp);
        return ans;
    }
};