class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stk;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            if(stk.size() != 0){
                int top = stk.back();
                while(stk.size() && temperatures[top] < temperatures[i]){
                    res[top] = i-top;
                    stk.pop_back();
                    top = stk.back();
                }
            }
            stk.push_back(i);
        }
        return res;
    }
};
