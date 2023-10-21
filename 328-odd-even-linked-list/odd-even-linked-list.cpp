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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans = head;
        ListNode* t=head;
        
        int n=0;
        while(t!=NULL){
            t=t->next;
            n++;
        }
        if(n<=2) return ans;
        ListNode* feven = head->next;
        ListNode* even = head->next;
        ListNode* odd = even->next;
        ListNode* podd = head;
        while(odd!=NULL && even!=NULL){
            ListNode* nxt = odd->next;
            even->next = nxt;
            podd->next = odd;
            odd->next = feven;
            podd = odd;
            even = even->next;
            if(even) odd=even->next;
        }

        return ans;
    }
};