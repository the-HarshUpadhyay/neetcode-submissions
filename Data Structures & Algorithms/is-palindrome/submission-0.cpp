class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string res;
        //to strip off everything except the literals;
        for(int i=0;i<n;i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                res+= tolower(s[i]);
            }
            else continue;
        }
        n = res.size();
        for(int i=0;i<n/2;i++){
            if(res[i]!= res[n-1-i]) return false;
        }
        return true;
    }
};
