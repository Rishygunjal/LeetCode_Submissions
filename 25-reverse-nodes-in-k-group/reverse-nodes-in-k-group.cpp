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

pair<ListNode*, ListNode*> reverse(ListNode* start,ListNode* end){
    ListNode* head = start;
    ListNode *prev = nullptr;
    while(head!=nullptr){
        ListNode *t = head->next;
        head->next = prev;
        prev = head;
        head=t;
    }

    return {prev,start};
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* ans=head;
        int j=0;
        while(ans!=nullptr){
            ans=ans->next;
            j++;
            if(ans==nullptr) return head;
            if(j==k-1) break;
        }

        ListNode* end = head;
        ListNode* start = new ListNode(-1);
        end=start;
        start->next = head;
        int i=0;
        while(end!=nullptr){
            end = end->next;
            i++;
            if(end==nullptr) break;
            if(i==k){
                //check end is null
                ListNode *t1 = end->next;
                ListNode *t2 = start->next;
                start->next = nullptr;
                end->next = nullptr;
                pair<ListNode*, ListNode*> p = reverse(t2,end);
                p.second->next = t1;
                start->next = p.first;
                i=0;
                start = p.second;
                end = p.second;
            }
        }

        return ans;
    }
};