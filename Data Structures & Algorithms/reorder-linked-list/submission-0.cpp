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
    void reorderList(ListNode* head) {
        vector<ListNode*> stk;
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        int counter = 0;
        while(fastptr && fastptr->next){
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            counter++;
        }
        while(slowptr){
            stk.push_back(slowptr);
            slowptr = slowptr->next;
        }
        for(int i=0;i<stk.size();i++) cout << stk[i]->val << " ";
        ListNode* curr = head;
        ListNode* next = NULL;
        while(!stk.empty() && counter--){
            ListNode* top = stk.back(); stk.pop_back();
            next = curr->next;
            curr->next = top;
            top->next = next;
            curr = next;
        }
        curr->next = NULL;

    }
};
