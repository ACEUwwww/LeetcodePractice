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
class inorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return {};
        recursive_inorderTraversal(root, res);
        return res;
    }

    void recursive_inorderTraversal(TreeNode* root, vector<int>& res) {
        if (root->left != nullptr) {
            recursive_inorderTraversal(root->left, res);
        }
        res.push_back(root->val);
        if (root->right != nullptr) {
            recursive_inorderTraversal(root->right, res);
        }
        return;
    }
};