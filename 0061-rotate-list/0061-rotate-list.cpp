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

 
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL ||k==0) return head;
        int c=1;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next;
            c++;
        }
        k=k%c;
        fast->next=head;
        int count=c-k;
        ListNode* temp=head;
        while(count>1&&temp!=NULL){
            temp=temp->next;
            count--;   
        }
      
            ListNode* nh=temp->next;
            temp->next=NULL;
            return nh;

        
        
  
        

    }
};