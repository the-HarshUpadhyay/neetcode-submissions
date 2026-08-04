class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<int> stk;
    vector<int> pref;
    int next(int price) {
        int counter = 1;
        while(!pref.empty() && stk.back() <= price){
            counter += pref.back();
            stk.pop_back();
            pref.pop_back();
        }
        stk.push_back(price);
        pref.push_back(counter);
        // cout << stk.back() << " " << pref.back() << "\n";
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */