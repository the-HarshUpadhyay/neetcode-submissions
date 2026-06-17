class Solution {
public:
    bool validPalindrome(string s) {
        bool flag = true;
        bool flag1 = true;
        bool flag2 = true;
        int l = 0;
        int h = s.size()-1;
        // use 2 pass technique once, if mismatch we'll increase only l, once if mismatch we'll decrease only h. Return the or of two flags
        while(l<h){
            if(s[l] == s[h]){
                l++;
                h--;
            }else{
                if(flag) l++;
                else{
                    flag1 = false;
                    break;
                }
                flag = false;
            }
        }
        flag = true;
        l = 0;
        h = s.size()-1;
        while(l<h){
            if(s[l] == s[h]){
                l++;
                h--;
            }
            else{
                if(flag) h--;
                else{
                    flag2 = false;
                    break;
                }
                flag = false;
            }
        }
        return (flag1 | flag2);
    }
};