class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        if(s.length() % 2 == 1) return false;
        for(char c:s){
            if(c == '{' || c == '(' || c == '['){
                stk.push_back(c);
            }
            else {
                if(c == '}'){
                    if(stk.empty() || stk.back() != '{') return false;
                    else stk.pop_back();
                }else if(c == ')'){
                    if(stk.empty() || stk.back() != '(') return false;
                    else stk.pop_back();
                }else if(c == ']'){
                    if(stk.empty() || stk.back() != '[') return false;
                    else stk.pop_back();
                }
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};
