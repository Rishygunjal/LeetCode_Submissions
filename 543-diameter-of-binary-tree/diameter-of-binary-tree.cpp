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

int height(TreeNode* root){
    if(root==NULL) return 0;
    int r = height(root->right);
    int l = height(root->left);
    return max(r,l)+1;
}

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int a = diameterOfBinaryTree(root->left);
        int b = diameterOfBinaryTree(root->right);
        int c = height(root->left);
        int d = height(root->right);
        cout << a << " "<< b <<" "<<c <<" "<<d<<endl;
        return max(max(a,b),c+d);
    }
};