class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Take the size of matrix in n.
        int n = grid.size();

        // If starting or ending cell is 1, then there is no way to reach from start to end.
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        vector<vector<int> > vis(n, vector<int>(n, 0));
        vector<pair<int, int> > moves = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};

        queue<vector<int> > bfs; // {x, y, distance}
        bfs.push({0, 0, 1});

        int ans = INT_MAX;
        while(!bfs.empty()) {
            // Compute distance for the front cell in the bfs queue.
            auto currCell = bfs.front();
            bfs.pop();

            // Extract x, y coordinate and distance travelled so far of the current cell.
            int x = currCell[0];
            int y = currCell[1];
            int dist = currCell[2];

            // If the last cell is reached then consider the distance for answer.
            if(x == n-1 && y == n-1) {
                ans = min(ans, dist);
                continue;
            }

            // If the cell was visited before with less distance than the current distance, skip it.
            if(vis[x][y] > 0 && vis[x][y] <= dist) {
                continue;
            }

            // Update vis matrix.
            vis[x][y] = dist;

            // Push the next cells to visit in the bfs queue.
            for(auto move : moves) {
                int nextX = x + move.first;
                int nextY = y + move.second;

                // If the next x coordinate is going out of bound, dont push the cell into queue.
                if(nextX < 0 || nextX >= n) {
                    continue;
                }

                // If the next y coordinate is going out of bound, dont push the cell into queue.
                if(nextY < 0 || nextY >= n) {
                    continue;
                }

                // If the next cell is 1, dont push the cell into queue.
                if(grid[nextX][nextY] == 1) {
                    continue;
                }

                // Push the next cell to visit in the queue.
                bfs.push({nextX, nextY, dist+1});
            }
        }

        // If answer was not updated, then the last cell didn't got reached, return -1.
        return (ans == INT_MAX) ? -1 : ans;
    }
};