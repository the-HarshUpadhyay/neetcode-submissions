class MinStack {
public:
    vector<int> stk;
    vector<int> prefMin;
    int minEle = INT_MAX;
    MinStack() {

    }
    
    void push(int val) {
        stk.push_back(val);
        if(prefMin.size() == 0)
            prefMin.push_back(val);
        else 
            prefMin.push_back(min(val,prefMin[prefMin.size()-1]));
    }
    
    void pop() {
        stk.pop_back();
        prefMin.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return prefMin.back();
    }
};
