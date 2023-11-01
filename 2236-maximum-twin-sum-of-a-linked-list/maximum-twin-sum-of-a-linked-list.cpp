/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0,ans=0;
        ListNode *t=head;
        while(t){
            n++;
            t=t->next;
        }
        vector<int> p1,p2;
        for(int i=0;i<n/2;i++){
            p1.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<n/2;i++){
            p2.push_back(head->val);
            head=head->next;
        }
        reverse(p2.begin(),p2.end());
        for(int i=0;i<n/2;i++){
            ans=max(ans,p1[i]+p2[i]);
        }
        return ans;
    }
};