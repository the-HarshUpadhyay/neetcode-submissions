class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
        for(string t:tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int op1 = stk.back(); stk.pop_back();
                int op2 = stk.back(); stk.pop_back();
                int res = 0;
                if(t=="+"){
                    res = op1+op2;
                }else if(t=="-"){
                    res = op2 - op1;
                }else if(t=="*"){
                    res = op2 * op1;
                }else if(t=="/"){
                    res = op2/op1;
                }
                stk.push_back(res);
            }else{
                stk.push_back(stoi(t));
            }
        }
        return stk[0];
    }
};
