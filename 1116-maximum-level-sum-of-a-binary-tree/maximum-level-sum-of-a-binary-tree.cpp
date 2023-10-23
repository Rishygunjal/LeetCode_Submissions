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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        pair<int,int> ans({root->val,1});
        int lvl=0;

        while(!q.empty()){
            int n=q.size();
            int sum=0;
            lvl++;
            while(n-->0){
                TreeNode* t = q.front();
                sum+=t->val;
                q.pop();
                if(t->left)  q.push(t->left);
                if(t->right)  q.push(t->right);
            }
            // cout<<sum<<lvl<<endl;
            if(sum>ans.first) ans = {sum,lvl};
        }

        return ans.second;
    }
};