class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hMap(26,0);
        int l = 0;
        int r = 0;
        int maxLength = 0;
        while(l<=r && r<n){
            hMap[s[r] - 'A']++;
            int winLength = r-l+1;

            //need to keep track of charMax
            
            char charMax = 'A';
            int charIdx = 0; 
            for(int i=0;i<26;i++){
                if(hMap[charMax - 'A'] < hMap[i]){
                    charIdx = i;
                    charMax = 'A' + i;
                }
            }
            
            //if no. of errors more than no of allowed replacement then shrink 
            if(winLength - hMap[charMax - 'A'] > k){
                hMap[s[l] - 'A']--;
                l++;
                hMap[s[r] - 'A']--;
                continue;
            }
            else {
                maxLength = max(winLength,maxLength);
                //cout << winLength << " L " << l << " R " << r << " max " << charMax << " " << hMap[charMax - 'A'] <<  endl;
            }
            r++;
            //if the total length - frequency of majority element is <= k then that subarray could be selected. 
            //need to figure out how to change the lower limit 
        }
        return maxLength;
    }
};