class MyCircularQueue {
public:
    struct Node{
        int val;
        Node* next;
        Node(int v):val(v),next(this){};
    };

    Node* rearptr = nullptr;
    Node* frontptr = nullptr;
    int n = 0;
    int size = 0;

    MyCircularQueue(int k) {
        n = k;
    }
    
    bool enQueue(int value) {
        if(size == n) return false;
        Node* temp = new Node(value);
        if(rearptr) {
            temp->next = rearptr->next;
            rearptr->next = temp;
        }
        else frontptr = temp;
        rearptr = temp;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(!size) return false;
        if(size == 1){
            delete(frontptr);
            frontptr = nullptr;
            rearptr = nullptr;
            size--;
            return true;
        }
        Node* temp1 = frontptr;
        Node* temp2 = rearptr;
        temp2->next = temp1->next;
        temp1->next = nullptr;
        frontptr = temp2->next;        
        delete(temp1);
        size--;
        return true;
    }
    
    int Front() {
        return (frontptr)?frontptr->val:-1;
    }
    
    int Rear() {    
        return (rearptr)?rearptr->val:-1;
    }
    
    bool isEmpty() {
        return !(size); 
    }
    
    bool isFull() {
        return (size==n); 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */