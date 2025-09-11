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
    int postOrderTraversal(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int left = postOrderTraversal(root->left,ans);
        int right = postOrderTraversal(root->right,ans);
        ans += abs(right) + abs(left);
        return (left + right + root->val-1);

    }

public:
    int distributeCoins(TreeNode* root) {
        int ans=0;
        int ans1 =postOrderTraversal(root,ans);
        return ans;
    }
};