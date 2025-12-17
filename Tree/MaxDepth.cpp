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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int maxDepth = 0;
        int depth = 1;
        maxDepthRecursive(root, depth, maxDepth);
        return maxDepth;
    }

    void maxDepthRecursive(TreeNode* root, int depth, int& maxDepth) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }
        if (root->left != nullptr) {
            maxDepthRecursive(root->left, depth + 1, maxDepth);
        }
        if (root->right != nullptr) {
            maxDepthRecursive(root->right, depth + 1, maxDepth);
        }
        return;
    }
    
    /* Better Solution
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    } */
};
