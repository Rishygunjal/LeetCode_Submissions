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

pair<bool,bool> populatemap(TreeNode* root,int p, int q, unordered_map<int,pair<bool,bool>>& m){
    if(root==NULL) return {0,0};
    pair<bool,bool> pr;
    if(root->val == p) pr.first=1;
    if(root->val == q) pr.second=1;
    
    pair<bool,bool> p1 = populatemap(root->left,p,q,m);
    pair<bool,bool> p2 = populatemap(root->right,p,q,m);
    pr.first = pr.first || p1.first || p2.first;
    pr.second = pr.second || p1.second || p2.second; 
    m[root->val] = pr;
    cout<<root->val<<" "<<pr.first<<" "<<pr.second<<endl;
    return pr;
}

TreeNode* findLCA(TreeNode* root, int p, int q, unordered_map<int,pair<bool,bool>>& m){
    pair<bool,bool> unity;
    // cout<<m[root->left->val].first<<m[root->left->val].second<<endl;
    if(root->left && m[root->left->val].first==1 && m[root->left->val].second==1){
        return findLCA(root->left,p,q,m);
    }else if(root->right && m[root->right->val].first==1 && m[root->right->val].second==1){
        return findLCA(root->right,p,q,m);
    }else{
        return root;
    }
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int,pair<bool,bool>> m;
        pair<bool,bool> pr = populatemap(root,p->val,q->val,m);
        return findLCA(root,p->val,q->val,m);
    }
};