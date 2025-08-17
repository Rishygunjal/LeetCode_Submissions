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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int n1=0;
        ListNode* t1 = head,*t2=head;
        while(t1!=nullptr){
            t1=t1->next;
            n1++;
        }
        int k = n1-n;

        if(k==0){
            return head->next;
        }else{
            while(k>1){
                t2=t2->next;
                k--;
            }
            t2->next=t2->next->next;
            return head;
        }

    }
};