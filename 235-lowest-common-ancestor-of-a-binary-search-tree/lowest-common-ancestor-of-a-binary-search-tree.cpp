/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ansNode){

    if(ansNode!=NULL) return 0;
    if(root==NULL) return 0;

    int ans=0;
    if(root==p || root==q) ans++;

    bool b1 = solve(root->left,p,q,ansNode);
    bool b2 = solve(root->right,p,q,ansNode);

    ans+=b1;
    ans+=b2;
    cout<<"ans "<<ans<<endl;

    if(ans==2) {
        cout<<"here?"<<endl;
        ansNode = root;
    }

    return ans;
    // bool b3 = solve(root->left,q);
    // bool b4 = solve(root->right,q);

}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ansNode = NULL;
        int t = solve(root,p,q,ansNode);
        return ansNode;
    }
};