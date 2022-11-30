class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Take map for storing frequencies and set for storing unique frequencies.
        unordered_map<int, int> mp;
        unordered_set<int> s;
        
        // Store the frequency of every array elements.
        for(int num : arr) {
            ++mp[num];
        }
        
        // Insert frequencies into a set.
        for(auto it : mp) {
            s.insert(it.second);
        }
        
        // If size of set and map is same, then all the frequencies are unique.
        return mp.size() == s.size();
    }
};