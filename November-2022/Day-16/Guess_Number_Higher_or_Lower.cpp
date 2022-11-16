/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // Pick is between 1 and n both inclusive.
        int start = 1, end = n;
        int ans = -1;
        
        // Binary Search Algorithm.
        while(start <= end) {
            // Find mid
            int mid = start + ((end - start) >> 1);
            
            // Guess mid. Check whether the guess is greater, less or equal to mid.
            int guessRes = guess(mid);
            
            // Perform the operation according to the above result.
            if(guessRes == -1) {
                end = mid - 1;
            } else if(guessRes == 1) {
                start = mid + 1;
            } else {
                ans = mid;
                break;
            }
        }
        
        return ans;
    }
};