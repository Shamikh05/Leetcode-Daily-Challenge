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
    // Fn to compute left and right height of a given tree node
    int computeHeight(TreeNode* root, bool computeLeftHeight) {
        int height = 0;
        
        if(computeLeftHeight == true) {
            // Keep traversing the left node until the end and calculate the height.
            while(root != NULL) {
                root = root->left;
                ++height;
            }
        } else {
            // Keep traversing the right node until the end and calculate the height.
            while(root != NULL) {
                root = root->right;
                ++height;
            }
        }
        
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        // Base Condition
        if(root == NULL) {
            return 0;    
        }
        
        // Compute left height and right height taking current node as root.
        int leftHeight = computeHeight(root, true);
        int rightHeight = computeHeight(root, false);
        
        // If both the heights are equal, Count the totals number of nodes from the formula 2^h - 1 and return it.
        if(leftHeight == rightHeight) {
            int nodeCount = pow(2, leftHeight) - 1;
            return nodeCount;
        }
        
        // Else do the above process for left subtree and right subtree.
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        
        // Return the number of nodes of current tree/subtree.
        return 1 + leftCount + rightCount;
    }
};