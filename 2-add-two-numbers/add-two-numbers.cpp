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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* prev = new ListNode(-1);
        ListNode* start = prev;
        while(l1!=nullptr && l2!=nullptr){
            int n = l1->val + l2->val + carry;
            int n1;
            if(n>=10){
                n1=n%10;
                carry = n/10;
            }else{
                n1 = n;
                carry =0;
            }
            cout<<n1<<" n1 "<<carry<<" c "<<endl;
            ListNode *t = new ListNode(n1);
            prev->next = t;
            prev = t;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1!=nullptr){
            int n = l1->val + carry;
            int n1;
            if(n>=10){
                n1=n%10;
                carry = n/10;
            }else{
                n1 = n;
                carry =0;
            }
            ListNode *t = new ListNode(n1);
            prev->next = t;
            prev = t;
            l1=l1->next;
        }

        while(l2!=nullptr){
            int n = l2->val + carry;
            int n1;
            if(n>=10){
                n1=n%10;
                carry = n/10;
            }else{
                n1 = n;
                carry =0;
            }
            ListNode *t = new ListNode(n1);
            prev->next = t;
            prev = t;
            l2=l2->next;
        }

        if(carry!=0){
            ListNode *t = new ListNode(carry);
            prev->next = t;
            carry=0;
        }

        return start->next;
    }
};