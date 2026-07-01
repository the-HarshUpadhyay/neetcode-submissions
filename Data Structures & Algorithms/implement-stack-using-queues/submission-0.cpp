class MyStack {
private:
    deque<int> dq;
public:
    MyStack() {
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        reverse(dq.begin(),dq.end());
        int top = dq.front();
        dq.pop_front();
        reverse(dq.begin(),dq.end());
        return top;
    }
    
    int top() {
        reverse(dq.begin(),dq.end());
        int top = dq.front();
        reverse(dq.begin(),dq.end());
        return top;
    }
    
    bool empty() {
        if(dq.size() > 0) return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */