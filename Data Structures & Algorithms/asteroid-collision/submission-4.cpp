class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //assuming left of stack is sorted
        vector<int> stk;
        for(int asteroid:asteroids){
            stk.push_back(asteroid);

            while(stk.size() >= 2 && stk.back() < 0){
                int op1 = stk.back(); stk.pop_back();
                int op2 = stk.back(); stk.pop_back();
                if(op2 > 0){
                    if(abs(op1) > op2) stk.push_back(op1);
                    else if(abs(op1) != op2) stk.push_back(op2);
                }else {
                    stk.push_back(op2);
                    stk.push_back(op1);
                    break;
                }
            }
        }
        return stk;
    }
};