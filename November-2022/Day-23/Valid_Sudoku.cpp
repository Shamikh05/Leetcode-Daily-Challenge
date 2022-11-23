class Solution {
/*  Block Index can be given as:
    (i / 3) is getting the row number
    ((i / 3) * 3) is giving the number of blocks before that block
    ((i / 3) * 3) + (j / 3) is giving the exact index of that block

    0 0 0 | 1 1 1 | 2 2 2
    0 0 0 | 1 1 1 | 2 2 2
    0 0 0 | 1 1 1 | 2 2 2
    ---------------------
    3 3 3 | 4 4 4 | 5 5 5
    3 3 3 | 4 4 4 | 5 5 5
    3 3 3 | 4 4 4 | 5 5 5
    ---------------------
    6 6 6 | 7 7 7 | 8 8 8
    6 6 6 | 7 7 7 | 8 8 8
    6 6 6 | 7 7 7 | 8 8 8
*/
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int> > row(9, vector<int>(9, 0));
        vector<vector<int> > col(9, vector<int>(9, 0));
        vector<vector<int> > blocks(9, vector<int>(9, 0));
        
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                // If the cell is empty, no need to check.
                if(board[i][j] == '.') {
                    continue;
                }
                
                // Compute the number index and block index.
                int num = board[i][j] - '1';
                int blockIdx = ((i / 3) * 3) + (j / 3);
                
                // If the same number was seen before in the same row, col or block, return false.
                if(row[i][num] == 1 || col[j][num] == 1 || blocks[blockIdx][num] == 1) {
                    return false;
                }
                
                // Mark the number index in row, col and blocks matrix as visited.
                row[i][num] = col[j][num] = blocks[blockIdx][num] = 1;
            }
        }
        
        return true;
    }
};