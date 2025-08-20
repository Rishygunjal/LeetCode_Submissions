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
    TreeNode* invertTree(TreeNode* root) {

        if(root==nullptr) return root;
        TreeNode* r = root->right;
        TreeNode* l = root->left;
        TreeNode* r1 = invertTree(r);
        TreeNode* l1 = invertTree(l);

        root->left = r;
        root->right = l;
        return root;

    }
};