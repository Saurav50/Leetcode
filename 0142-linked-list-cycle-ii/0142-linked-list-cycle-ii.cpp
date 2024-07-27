/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* temp=head;
//         unordered_set<ListNode*> s;
//         while(temp!=NULL){
//             if(s.find(temp)!=s.end()){
//                 return temp;
//             }
//             s.insert(temp);
//             temp=temp->next;
//         }
        
//         return NULL;
//     }
     ListNode *detectCycle(ListNode *head) {
       ListNode* slow=head;
       ListNode* fast=head;
       bool hasCycle=false;
       while(fast!=NULL&&fast->next!=NULL){
           
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast){
            hasCycle=true;
            break;
           } 
       }
        if(!hasCycle) return NULL;
        slow=head;
        while(slow!=NULL){
            if(slow==fast) return slow;
            slow=slow->next;
            fast=fast->next;
        }

        
        return NULL;
    }
};