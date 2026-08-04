class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<int> stk;
    int next(int price) {
        int counter = 1;
        vector<int> stkTemp = stk;
        while(!stkTemp.empty() && stkTemp.back() <= price){
            stkTemp.pop_back();
            counter++;
        }
        stk.push_back(price);
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */