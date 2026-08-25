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
        Node* temp = head;
        if(head == nullptr) return nullptr;
        //interweaving deepcopy to original list
                                                      
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        //attaching randoms
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* temp1 = head->next;
        Node* head2 = temp1;
        temp = head;
        while(temp1){
            temp->next = temp1->next;
            temp = temp->next;
            if(temp) temp1->next = temp->next;
            temp1 = temp1->next;
        }
        return head2;

    }
};
