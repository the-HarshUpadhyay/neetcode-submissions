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
        int carry = 0;
        int sum = 0;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        ListNode* tempNode;
        while(l1 && l2){
            sum = (l1->val+l2->val)+carry;
            carry = (sum)/10;

            //for now store in both lists and when we get to know which list is bigger we will store in it to save up on auxillary space            
            tempNode = new ListNode(sum%10);
            temp->next = tempNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            // cout << "INSIDE L1 \n";
            sum = l1->val + carry;
            carry = sum/10;
            tempNode = new ListNode(sum%10);
            temp->next = tempNode;   
            temp = temp->next;         
            l1 = l1->next;
        }

        while(l2) {
            // cout << "INSIDE L2 \n";
            sum = l2->val + carry;
            carry = sum/10;
            tempNode = new ListNode(sum%10);
            temp->next = tempNode;
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry){
            ListNode* tempNode = new ListNode(carry);
            temp->next = tempNode;
        }
        return dummy.next;
    }
};
