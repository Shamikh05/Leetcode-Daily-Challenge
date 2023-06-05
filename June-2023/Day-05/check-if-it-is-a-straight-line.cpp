class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        // Take initial input from first 2 points to make the eq. of straight line.
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0]; // x2 - x1
        int dy = coordinates[1][1] - coordinates[0][1]; // y2 - y1

        for(int i=2; i<n; ++i) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // (x2 - x1)(y - y1) = (y2 - y1)(x - x1)
            int lhs = dx*y - dx*y1;
            int rhs = dy*x - dy*x1;

            if (lhs != rhs) {
                return false;
            }
        }

        return true;
    }
};