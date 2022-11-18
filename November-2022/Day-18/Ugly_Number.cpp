class Solution {
public:
    bool isUgly(int n) {
        // Edge Case
        if(n == 0) {
            return false;
        }
        
        // First divide by 2 then by 3 then by 5.
        vector<int> primeFactors = {2, 3, 5};
        for(int currFact : primeFactors) {
            // Divide until n is no longer divisible by the current factor.
            while(n % currFact == 0) {
                n /= currFact;
            }
        }
        
        // If n is reduced to 1 by dividing it to 2, 3 and 5 then it is an ugly number else not.
        return n == 1;
    }
};