class Solution {
private:
    void countSort(vector<int> &arr) {
        int n = arr.size();
        
        if(n == 0) {
            return;
        }
        
        int maxElement = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxElement+1, 0);
        
        for(int i=0; i<n; ++i) {
            ++freq[arr[i]];
        }
        
        int arrIdx = 0;
        for(int i=1; i<=maxElement; ++i) {
            if(freq[i] > 0) {
                arr[arrIdx++] = i;
            }
        }
    }
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> mp;
        
        for(auto it : matches) {
            int winner = it[0];
            int loser = it[1];
            
            mp[winner] += 0;
            ++mp[loser];
        }
        
        vector<int> zeroLost, oneLost;
        for(auto it : mp) {
            int player = it.first;
            int matchesLost = it.second;
            
            if(matchesLost == 0) {
                zeroLost.push_back(player);
            } 
            else if(matchesLost == 1) {
                oneLost.push_back(player);
            }
        }
        
        countSort(zeroLost);
        countSort(oneLost);
        
        vector<vector<int> > ans = {zeroLost, oneLost};
        return ans;
    }
};