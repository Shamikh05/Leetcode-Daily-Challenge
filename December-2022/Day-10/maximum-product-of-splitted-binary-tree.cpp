/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    long long totalSum, maxProd;

    long long postorderTrav(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        // Get the sum of left and right subtrees.
        long long leftSum = postorderTrav(root->left);
        long long rightSum = postorderTrav(root->right);

        // Add current node value in left and right sum to get the current Sum.
        long long currSum = root->val + leftSum + rightSum;
        
        // Take the product of both the partitions sum.
        long long prod = currSum * (totalSum - currSum);
        // If the prod is greater than previous products, update maxProd variable.
        maxProd = max(maxProd, prod); 

        return currSum;
    }
public:
    int maxProduct(TreeNode* root) {
        // Get the sum of all the nodes inside tree.
        totalSum = postorderTrav(root);

        // Get the maximum product after splitting.
        maxProd = 0;
        postorderTrav(root);

        // Before returning the final answer, mod it with 10^9 + 7.
        return maxProd % (int)(1e9 + 7);
    }
};