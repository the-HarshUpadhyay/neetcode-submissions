class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int v):key(k),value(v),prev(nullptr),next(nullptr){};
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    int capacity = 0;
    int size = 0;
    unordered_map<int,Node*> nodeMap;

    

    LRUCache(int n) {
        capacity = n;
        //two dummy nodes to handle edge cases
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    void moveToEnd(Node* temp){
        if(temp->prev)temp->prev->next = temp->next;
        if(temp->next)temp->next->prev = temp->prev;
        temp->prev = temp->next = nullptr;

        temp->prev = tail->prev;
        temp->next = tail;
        tail->prev->next = temp;
        tail->prev = temp;
    }

    void deleteFromStart(){
        Node* temp = head->next;
        head->next = temp->next;
        head->next->prev = head;
        temp->next = nullptr;
        temp->prev = nullptr;
        nodeMap.erase(temp->key);
        delete(temp); 
        size--;
    }

    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) return -1;
        moveToEnd(nodeMap[key]);
        return nodeMap[key]->value;    
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key) == nodeMap.end()){
            Node* temp = new Node(key,value);
            moveToEnd(temp);
            nodeMap[key] = temp;
            size++;
        }
        else {
            nodeMap[key]->value = value;
            moveToEnd(nodeMap[key]);
        }

        if(size>capacity){
            deleteFromStart();
        }
    }

};
