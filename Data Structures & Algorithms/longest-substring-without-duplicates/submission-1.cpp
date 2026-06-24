class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        //int r = 0;
        unordered_map<char,int> hSet;
        int winSize = 0;
        int i =0;
        //determine window size by consecutively iterating the string, window size is r-l+1. maintain hashmap to ensure uniqueness, if we find that a character is not unique, we'd shrink the window as
        for(int i=0;i<n;i++){
            //if an element is not unique
            if(hSet.find(s[i]) != hSet.end()){
                if(l<=hSet[s[i]]) l = hSet[s[i]]+1;
            }
            hSet[s[i]] = i;
            //r++;
            winSize = max(winSize,i-l+1);
            //cout << l << " " << i << endl;
        }
        return winSize;
    }
};
