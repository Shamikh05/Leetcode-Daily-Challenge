class Solution {
private:
    vector<char> vowels;
    
    // Fn to check whether the passed character is vowel or not.
    bool isVowel(char ch) {
        // Loop over all the vowels and compare with the input character.
        for(char vow : vowels) {
            if(ch == vow) {
                return true;
            }
        }
        
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Calculate the number of vowels in 1st and 2nd half of string.
        int leftVowelCnt = 0, rightVowelCnt = 0;
        for(int i=0; i<n; ++i) {
            if(isVowel(s[i])) {
                i < (n/2) ? ++leftVowelCnt : ++rightVowelCnt;
            }
        }
        
        return leftVowelCnt == rightVowelCnt;
    }
};