class Solution {
private:
    void dfs(
            int row, 
            int col,
            int emptySpaces,
            int &dstRow,
            int &dstCol,
            vector<vector<int>> &grid,
            int &m,
            int &n,
            vector<vector<int>> &vis,
            int &ans
        ) {
            if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==-1 || vis[row][col]==1) {
                return;
            }

            if(row==dstRow && col==dstCol && emptySpaces==0) {
                ++ans;
                return;
            }

            vis[row][col] = 1;
            dfs(row+1, col, emptySpaces-1, dstRow, dstCol, grid, m, n, vis, ans);
            dfs(row, col+1, emptySpaces-1, dstRow, dstCol, grid, m, n, vis, ans);
            dfs(row-1, col, emptySpaces-1, dstRow, dstCol, grid, m, n, vis, ans);
            dfs(row, col-1, emptySpaces-1, dstRow, dstCol, grid, m, n, vis, ans);
            vis[row][col] = 0;
        }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int srcRow, srcCol, dstRow, dstCol, emptySpaces = 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 0) {
                    ++emptySpaces;
                } else if(grid[i][j] == 1) {
                    srcRow = i;
                    srcCol = j;
                } else if(grid[i][j] == 2) {
                    dstRow = i;
                    dstCol = j;
                }
            }
        }

        int ans = 0;
        dfs(srcRow, srcCol, emptySpaces, dstRow, dstCol, grid, m, n, vis, ans);
        return ans;
    }
};