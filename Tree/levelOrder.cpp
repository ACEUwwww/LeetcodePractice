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
class levelOrder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        if (root == nullptr) 
            return res;
        int res_ptr = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back({});
            int loop = q.size();
            for (int i = 0; i < loop; i++) {
                res[res_ptr].push_back(q.front()->val);
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            res_ptr++;

        }
        return res;
    }
};