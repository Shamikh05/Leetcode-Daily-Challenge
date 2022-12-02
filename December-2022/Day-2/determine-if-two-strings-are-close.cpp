class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int wordLen1 = word1.length();
        int wordLen2 = word2.length();
        
        // If length of both the strings are not equal, then they cannot be close.
        if(wordLen1 != wordLen2) {
            return false;
        }
        
        // Define 2 frequency tables for 2 input strings.  
        vector<int> freq1(26, 0), freq2(26, 0);
        
        // Get the character frequencies of both the strings.
        for(int i=0; i<wordLen1; ++i) {
            ++freq1[word1[i]-'a'];
            ++freq2[word2[i]-'a'];
        }
        
        // If there is any character which is present in one string but not in other string, return false.
        for(int i=0; i<26; ++i) {
            if(freq1[i] > 0 && freq2[i] == 0) {
                return false;
            }
            
            if(freq1[i] == 0 && freq2[i] > 0) {
                return false;
            }
        }
        
        // Sort both the frequency tables for comparison. 
        // Sorting will take constant time here since length of frequency table is 26.
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        // If both the sorted freuency tables are equal, strings can be made close.
        return freq1 == freq2;
    }
};