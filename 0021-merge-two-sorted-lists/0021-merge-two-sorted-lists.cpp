class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2!=NULL) return list2;
        if(list2==NULL&&list1!=NULL) return list1;
        
        
        ListNode *newListHead = NULL;
        ListNode *newListTail = NULL;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                if (newListHead == NULL) {
                    newListHead = list1;
                    newListTail = list1;
                } else {
                    newListTail->next = list1;
                    newListTail = list1;
                }
                list1 = list1->next;
            } else {
                if (newListHead == NULL) {
                    newListHead = list2;
                    newListTail = list2;
                } else {
                    newListTail->next = list2;
                    newListTail = list2;
                }
                list2 = list2->next;
            }
        }

        if (list1 != NULL) newListTail->next = list1;
        if (list2 != NULL) newListTail->next = list2;
        
        return newListHead;
    }
};
