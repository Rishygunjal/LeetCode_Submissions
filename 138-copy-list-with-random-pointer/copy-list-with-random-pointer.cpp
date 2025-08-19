/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t1=head,*t2=head;
        unordered_map<Node*, int> m1;
        unordered_map<int,Node*> m2;
        Node *prev = new Node(-1);
        prev -> next = t1; 
        int i=0,j=0;
        while(t1!=nullptr){
            Node* t = new Node(t1->val);
            m1[t1]=i;
            m2[i]=t;
            i++;
            prev->next = t;
            prev = t;
            t1 = t1->next;
        }
        cout<<"checkpoint 1"<<endl;

        while(t2!=nullptr){
            cout<<"checkpoint 2"<<endl;
            int j = m1[t2];
            if(t2->random!=nullptr){
                int i = m1[t2->random];
                m2[j]->random = m2[i];
            }else{
                m2[j]->random = nullptr;
            }
            t2 = t2->next;
        }

        return m2[0];
        
    }
};