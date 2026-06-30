class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hMap;
        for(char c:t) hMap[c]++;
        int l =0;
        int counter = 0;
        int minLength = INT_MAX;
        int minL = -1;
        for(int r=0;r<s.size();r++){
            if(hMap.find(s[r]) != hMap.end()){
                if(hMap[s[r]] > 0){
                    counter++;
                }
                hMap[s[r]]--;  
            }
            while(counter == t.size()){
                if(minLength > r-l+1){
                    minL = l;
                    minLength = r-l+1;
                }
                if(hMap.find(s[l]) != hMap.end()){
                    hMap[s[l]]++;
                    if(hMap[s[l]] > 0) counter --;
                }
                l++;
            }
        }
        if(minL == -1){
            return ""; 
        }
        return s.substr(minL,minLength);
    }
};
