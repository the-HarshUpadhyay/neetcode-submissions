class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stk;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            if(stk.size() != 0){
                while(stk.size() && temperatures[stk.back()] < temperatures[i]){
                    res[stk.back()] = i-stk.back();
                    stk.pop_back();
                }
            }
            stk.push_back(i);
        }
        return res;
    }
};
