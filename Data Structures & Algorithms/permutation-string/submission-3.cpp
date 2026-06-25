class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        unordered_map<char,int> hMap;
        unordered_map<char,int> tMap;
        for(char s: s1) hMap[s]++;
        tMap = hMap;
        for(int r=0;r<s2.size();r++){
            if(tMap.find(s2[r]) != tMap.end() && tMap[s2[r]] > 0){
                tMap[s2[r]]--;
            }else if(tMap.find(s2[r]) == tMap.end()){
                // if s2[r] is not in s1 than window would need to excluse all elements till r and reset map counts
                l = r+1;
                tMap = hMap;
            }else{
                // if s2[r] existed but is more than reqd, we can shrink l till the next first occurence of s2[r] in the window
                while(s2[l] != s2[r]){
                    //undo the decrements 
                    tMap[s2[l]]++;
                    l++;
                }
                tMap[s2[l]]++;
                l++;
                r--;
            }

            int size = r-l+1;
            cout << l << " " << r << " " << size << endl; 
            if(size == s1.size()) return true;
        }
        return false;
    }
};
