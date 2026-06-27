class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for(string operation:operations){
            if(operation == "C"){
                stk.pop_back();
            }
            else if(operation == "D"){
                stk.push_back(stk.back()*2);
            }
            else if(operation == "+"){
                int op1 = stk.back();
                stk.pop_back();
                int op2 = stk.back();
                stk.push_back(op1);
                stk.push_back(op1 + op2);
            }else{
                int x = stoi(operation);
                stk.push_back(x);
            }
            // cout << operation << " " << stk.back() << "\n";
        }
        int sum = accumulate(stk.begin(),stk.end(),0);
        return sum;
    }
};