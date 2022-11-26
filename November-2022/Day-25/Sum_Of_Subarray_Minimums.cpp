class Solution {
# define mod 1000000007
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        int sum = 0;
        stack<int> leftSt, rightSt;
        vector<int> rightExt(n, 0);
        
        // Get the right extent of every index using monotonic stack.
        for(int i=n-1; i>=0; --i) {
            while(!rightSt.empty() and arr[i] <= arr[rightSt.top()]) {
                rightSt.pop();
            }
            
            if(rightSt.empty() == false) {
                rightExt[i] = rightSt.top() - i;
            } else {
                rightExt[i] = n - i;
            }
            
            rightSt.push(i);
        }
        
        // Get the left extent of every index. Multiply it with current idx number and add it in sum (final ans).
        for(int i=0; i<n; ++i) {
            while(!leftSt.empty() and arr[i] < arr[leftSt.top()]) {
                leftSt.pop();
            }
            
            int leftExt = i + 1;
            if(leftSt.empty() == false) {
                leftExt = i - leftSt.top();
            }
                        
            long long subArrs = leftExt * rightExt[i];
            sum = ((sum % mod) + ((subArrs * arr[i]) % mod) % mod) % mod;
            
            leftSt.push(i);
        }
        
        return sum;
    }
};