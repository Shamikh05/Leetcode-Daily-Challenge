class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        map<char, string> mp1;
        map<string, char> mp2;

        stringstream ss(s);
        string word;
        int count = 0;

        int i=0;
        while(ss >> word) {
            if(i<n && mp1.find(pattern[i]) == mp1.end() && mp2.find(word) == mp2.end()) {
                mp1[pattern[i]] = word;
                mp2[word] = pattern[i];
            }

            if(i<n && mp2[word] != pattern[i]) {
                return false;
            }

            i++;
            count++;
        }

        if(count != n) {
            return false;
        }

        return true;
    }
};