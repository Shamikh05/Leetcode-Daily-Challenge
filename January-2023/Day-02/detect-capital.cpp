class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        if(n == 1) {
            return true;
        }
        
        bool firstLetter = islower(word[0]), secondLetter = isupper(word[1]);
        for(int i=1;i<n;++i) {
            bool ithLetter = isupper(word[i]);
            
            if((secondLetter != ithLetter) or (firstLetter and secondLetter)) {
                return false;
            }
        }
        
        return true;
    }
};