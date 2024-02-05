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
    int length(ListNode* head){
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length += 1;
            temp = temp->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = length(head);
        int c = l - n;

        if (c == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* temp = head;
        while (temp != NULL) {
            if (c == 1) {
                ListNode* toRemove = temp->next;
                temp->next = temp->next->next;
                delete toRemove;
                break;
            }
            c--;
            temp = temp->next;
        }

        return head;
    }
};
