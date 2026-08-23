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
    unordered_map<Node*,Node*> hMap;
    bool isAvailable(Node* node){
        if(hMap.find(node) == hMap.end()) return false;
        return true;
    }
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* temp1 = &dummy;
        Node* temp2 = head;
        while(temp2){
            //deep copy of temp
            if(!isAvailable(temp2)){
                hMap[temp2] = new Node(temp2->val);
            }
            //deep copy of random
            if(temp2->random && !isAvailable(temp2->random)){
                hMap[temp2->random] = new Node(temp2->random->val);
            }
            temp1->next = hMap[temp2];
            temp1->next->random = hMap[temp2->random];
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        return dummy.next;
    }
};
