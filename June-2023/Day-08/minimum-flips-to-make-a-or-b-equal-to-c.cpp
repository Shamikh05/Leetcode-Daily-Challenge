class Solution {
    /*
        a | b   c
        1   1   0    +2
        1   0   0    +1
        0   1   0    +1
        0   0   1    +1
    */
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while(a || b || c) {
            int aBit = a&1, bBit = b&1, cBit = c&1;

            if((aBit | bBit) != cBit) {
                ans += (aBit & bBit) ? 2 : 1;
            }

            a >>= 1, b >>= 1, c >>= 1;
        }

        return ans;
    }
};