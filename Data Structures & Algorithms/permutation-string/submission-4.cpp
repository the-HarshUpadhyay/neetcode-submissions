class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        unordered_map<char,int> hMap;
        for(int i=0;i<26;i++) hMap['a'+i] = 0;
        unordered_map<char,int> wMap;
        for(char s: s1) hMap[s]++;
        for(int r=0;r<s2.size();r++){
            wMap[s2[r]]++;
            while(wMap[s2[r]] > hMap[s2[r]]){
                wMap[s2[l]]--;
                l++;
            }

            int size = r-l+1;
            cout << l << " " << r << " " << size << endl; 
            if(size == s1.size()) return true;
        }
        return false;
    }
};
