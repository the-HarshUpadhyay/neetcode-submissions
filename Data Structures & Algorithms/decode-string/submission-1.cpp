class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return fun(s,i);
    }
    string fun(string s,int& i){
        int number = 0;
        string res = "";
        while(i<s.size()){
            if(s[i] == '['){
                i++;
                string temp = fun(s,i);
                for(int j=0;j<number;j++){
                    res += temp;
                }
                number = 0;
            }
            else if(isdigit(s[i])){
                while(isdigit(s[i])){
                    number *= 10;
                    number += (s[i] - '0');
                    i++;
                }
            }   
            else if(s[i]==']'){
                i++;
                return res;
            }else{
                res += s[i];
                i++;
            }
        }
        return res;
    }
};