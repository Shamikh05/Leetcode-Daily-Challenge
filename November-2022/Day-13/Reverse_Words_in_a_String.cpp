class Solution {
public:
    string reverseWords(string s) {
        // Reverse the complete string for getting the last word of the string at first.
        reverse(s.begin(), s.end());
        
        // Taking word for storing each word of the string.
        string word;
        stringstream ss(s);
        
        // Extract each word by using stringstream class and add to the answer string.
        string ans = "";
        while(ss >> word) {
            // Reverse the word to get the original word.
            reverse(word.begin(), word.end());
            // Append the word to answer string.
            ans += word + " ";
        }
        
        // Take out the extra space from the end of the answer string.
        ans.pop_back();
        
        return ans;
    }
};