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
    int preorderTrav(TreeNode* root, int maxVal, int minVal) {
        // If there are no nodes to explore in the curr. recursion call, return the difference. 
        if(root == NULL) {
            return (maxVal - minVal);
        }

        // Get the current node value.
        int currVal = root->val;

        // Get the maximum and minimum node value in the current recursion call.
        maxVal = max(maxVal, currVal);
        minVal = min(minVal, currVal);

        // Explore left and right subtree.
        int leftMax = preorderTrav(root->left, maxVal, minVal);
        int rightMax = preorderTrav(root->right, maxVal, minVal);

        // Return the maximum value achieved from the left and right subtree recursion call.
        return max(leftMax, rightMax);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        // Pass root as the max. and min. value because for root, there are no ancestors.
        return preorderTrav(root, root->val, root->val);
    }
};