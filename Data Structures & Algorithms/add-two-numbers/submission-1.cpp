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
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* ans = h2;
        ListNode* prev;
        while(l1 && l2){
            sum = (l1->val+l2->val)+carry;
            carry = (sum)/10;

            //for now store in both lists and when we get to know which list is bigger we will store in it to save up on auxillary space            
            l1->val = sum%10;
            l2->val = sum%10;

            prev = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            // cout << "INSIDE L1 \n";
            sum = l1->val + carry;
            carry = sum/10;
            l1->val = sum%10;
            prev = l1;
            l1 = l1->next;
            ans = h1;
        }

        while(l2) {
            // cout << "INSIDE L2 \n";
            sum = l2->val + carry;
            carry = sum/10;
            l2->val = sum%10;
            prev = l2;
            l2 = l2->next;
        }

        if(carry){
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }
        return ans;
    }
};
