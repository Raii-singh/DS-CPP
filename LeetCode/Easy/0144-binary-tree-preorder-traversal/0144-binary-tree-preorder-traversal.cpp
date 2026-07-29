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
    vector<int> ans;
    void fx(TreeNode* root){
        if(root == nullptr) return;

        ans.push_back(root->val);
        fx(root->left);
        fx(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        fx(root);
        return ans;
    }
};