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

void merge(ListNode* head1, ListNode* head2){
    while(head1!=nullptr && head2!=nullptr){
        ListNode* t1 = head1->next;
        ListNode* t2 = head2->next;
        head1->next=head2;
        head2->next = t1;
        head1 = t1,head2=t2;
    }
}

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;

    while(head!=nullptr){
        ListNode* t = head->next;
        head->next = prev;
        prev = head;
        head = t;
    }

    return prev;
}


public:
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* t=head;
        while(t!=nullptr){
            t=t->next;
            n++;
        }

        ListNode* t1=head;
        int k = n-n/2;
        while(k>1){
            t1=t1->next;
            k--;
        }

        ListNode* t2 = t1->next;
        t1->next = nullptr;
        ListNode* head2 = reverse(t2);

        merge(head,head2);
        // return head;
    }
};