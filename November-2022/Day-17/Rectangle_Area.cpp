class Solution {
private:
    long long computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len = 0, wid = 0;
        
        /*
            Case 1: If bx1 lies between ax1 and ax2.
            Case 2: If bx2 lies betwwen ax1 aand ax2.
            Case 3: If ax1 and ax2 both lies between bx1 and bx2
        */
        // Calculate length on the basis of above conditions.
        if(bx1 < ax2 && bx1 >= ax1) {
            len = min(ax2, bx2) - bx1;
        } else if(bx2 > ax1 && bx2 <= ax2) {
            len = bx2 - max(ax1, bx1);
        } else if(ax1 >= bx1 && ax2 <= bx2) {
            len = ax2 - ax1;
        }
        
        
        /*
            Case 1: If by1 lies between ay1 and ay2.
            Case 2: If by2 lies betwwen ay1 aand ay2.
            Case 3: If ay1 and ay2 both lies between by1 and by2
        */
        // Calculate width on the basis of above conditions.
        if(by1 < ay2 && by1 >= ay1) {
            wid = min(ay2, by2) - by1;
        } else if(by2 > ay1 && by2 <= ay2) {
            wid = by2 - max(ay1, by1);
        } else if(ay1 >= by1 && ay2 <= by2) {
            wid = ay2 - ay1;
        }
        
        // Return overlapping area.
        long long area = len * wid;
        return area;
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate the area of first rectangle.
        long long area1 = (ax2 - ax1) * (ay2 - ay1);
        
        // Calculate the area of second rectangle.
        long long area2 = (bx2 - bx1) * (by2 - by1);
        
        // Calculate the overlapping area.
        long long overlapArea = computeOverlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        
        // Add the area of 2 rectangles and subtract overlapping area.
        return area1 + area2 - overlapArea;
    }
};