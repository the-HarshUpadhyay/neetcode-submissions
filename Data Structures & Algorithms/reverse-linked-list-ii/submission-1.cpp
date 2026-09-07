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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode Dummy(0,head);
        ListNode* curr = head;
        ListNode* prev = &Dummy;
        for(int i=1;i<left;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* temp = prev->next;
        for(int i=0;i<right-left;i++){
            temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return Dummy.next;
    }
};