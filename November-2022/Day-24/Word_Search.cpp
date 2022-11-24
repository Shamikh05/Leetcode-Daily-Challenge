class Solution {
private:
    int m, n;
    
    bool checkDimOutsideBoard(int row, int col) {
        // If any of the row or col going outside the board, return true, else return false.
        if(row < 0 || row >= m || col < 0 || col >= n) {
            return true;
        }
        return false;
    }
    
    bool dfs(int row, int col, int wordIdx, vector<vector<char>> &board, string &word, vector<vector<bool> > &vis) {
        // If all the characters of word are scanned, then the word must be present inside the board.
        if(wordIdx == word.size()) {
            return true;
        }
        
        // If row/col is outside the board, return false.
        bool isDimOutsideBoard = checkDimOutsideBoard(row, col);
        if(isDimOutsideBoard) {
            return false;
        }
        
        // If char at board[row][col] is not same as char at word[wordIdx], return false.
        if(board[row][col] != word[wordIdx]) {
            return false;
        }
        
        // If cell already visited in same dfs call, return false.
        if(vis[row][col] == true) {
            return false;
        }
        
        // Mark the current cell as visited.
        vis[row][col] = true;
        
        // Go in all 4 directions.
        bool goLeft = dfs(row, col-1, wordIdx+1, board, word, vis);
        bool goUp = dfs(row-1, col, wordIdx+1, board, word, vis);
        bool goRight = dfs(row, col+1, wordIdx+1, board, word, vis);
        bool goDown = dfs(row+1, col, wordIdx+1, board, word, vis);
        
        // Unmark the current visited cell so that cell can be visited in different dfs call.
        vis[row][col] = false;
        
        // If any of the direction call result comes out to be true, return true.
        return (goLeft || goUp || goRight || goDown);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Get the row and col of board. 
        m = board.size();
        n = board[0].size();
        
        // Take a separate 2D array for marking the cell which is visited.
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        
        int idx = 0;
        // Loop through the board cells to look for initial character.
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                // If the current character is not the same as first character of word, skip the character.
                if(board[i][j] != word[idx]) {
                    continue;
                }
                
                // Check if word exists or not, immediately return true if the word exists.
                bool wordExist = dfs(i, j, idx, board, word, vis);
                if(wordExist) {
                    return true;
                }
            }
        }
        
        // Word does not exist in the board, return false.
        return false;
    }
};