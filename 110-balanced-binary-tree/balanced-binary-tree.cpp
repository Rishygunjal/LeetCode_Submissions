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

pair<int,bool> rec(TreeNode* root){
    if(root==NULL) return {0,1};
    pair<int,bool> l = rec(root->left);
    pair<int,bool> r = rec(root->right);
    if(!r.second || !l.second){
        return {0,0};
    }else{
        if(abs(l.first-r.first)>1){
            return {0,0};
        }else{
            return {max(r.first,l.first)+1,1};
        }
    }
}

public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return rec(root).second;
    }
};