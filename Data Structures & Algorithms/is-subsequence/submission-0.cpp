class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(j<s.size() && i<t.size()){
            if(s[j] == t[i]){
                cout << s[j] << " " << t[i] << endl;
                j++;
            }
            i++;
        }
        cout << j << " " << i;
        return (j == s.size());
    }
};