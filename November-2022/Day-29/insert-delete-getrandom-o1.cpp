class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> values;
    int totalVals; 
public:
    RandomizedSet() {
        totalVals = 0;
    }
    
    bool insert(int val) {
        // If val already present, return false.
        if(mp[val] > 0) {
            return false;
        }
        
        // val is not present inside the set, insert and return true;
        values.push_back(val);
        ++totalVals;
        mp[val] = totalVals;
        
        return true;
    }
    
    bool remove(int val) {
        // If val is not present, return false.
        if(mp[val] == 0) {
            return false;
        }
        
        // Value is present, delete it by swapping val with last number in the vector.
        mp[values[totalVals-1]] = mp[val];
        swap(values[totalVals-1], values[mp[val]-1]);
        // Update the indices in map.
        mp[val] = 0;
        values.pop_back();
        --totalVals;
        
        return true;
    }
    
    int getRandom() {
        return values[rand() % totalVals];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */