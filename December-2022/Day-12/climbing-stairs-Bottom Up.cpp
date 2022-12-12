class Solution {
public:
    int climbStairs(int n) {
        int secondLastStep = 1, lastStep = 1;

        for(int i=2; i<=n; ++i) {
            int waysToReach = secondLastStep + lastStep;
            secondLastStep = lastStep;
            lastStep = waysToReach;
        }

        return lastStep;
    }
};