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

    int ans=0;

void Callongestzigzag(TreeNode* root, bool b,int t){
    ans=max(ans,t);
    if(root==NULL) return;

    // int ans1 = Callongestzigzag(root->right,!b);
    // int ans = Callongestzigzag(root->right,b);
    // int ans3 = Callongestzigzag(root->left,!b);
    // int ans4 = Callongestzigzag(root->left,b);

    if(b) {
        Callongestzigzag(root->right,!b,t+1);
        Callongestzigzag(root->left,!b,0);
    }
    else {
        Callongestzigzag(root->left,!b,t+1);
        Callongestzigzag(root->right,!b,0);
    }
    
}

public:
    int longestZigZag(TreeNode* root) {
        // int ans = 0;
        Callongestzigzag(root,0,0);
        Callongestzigzag(root,1,0);
        return ans-1;
    }
};