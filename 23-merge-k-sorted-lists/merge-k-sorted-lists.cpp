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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* ans = new ListNode(-1);
        ListNode* prev = ans;
        while(true){
            unordered_map<int,int> mp;
            int mini=INT_MAX;
            for(int i=0;i<n;i++){
                if(lists[i]==nullptr) continue;
                int t = lists[i]->val;
                mini = min(mini,t);
                mp[t]=i;
            }
            if(mp.size()==0) {
                break;
            }
            ListNode* tnode = new ListNode(lists[mp[mini]]->val);
            lists[mp[mini]] = lists[mp[mini]]->next;
            prev -> next = tnode;
            prev = tnode;
        }

        return ans->next;
    }
};