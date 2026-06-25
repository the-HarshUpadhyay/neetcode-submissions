class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> hMapFreq;
        unordered_map<char,int> hMapIdx;
        char charMax = s[0];
        int l = 0;
        int r = 0;
        int maxLength = 0;
        while(l<=r && r<n){
            hMapFreq[s[r]]++;
            int winLength = r-l+1;

            //need to keep track of charMax
            if(hMapFreq[s[r]] >= hMapFreq[charMax]){
                charMax = s[r];
            }
            //if no. of errors more than no of allowed replacement then shrink 
            if(winLength - hMapFreq[charMax] > k){
                hMapFreq[s[l]]--;
                l++;
                hMapFreq[s[r]]--;
                continue;
            }
            else {
                maxLength = max(winLength,maxLength);
                cout << winLength << " L " << l << " R " << r << " max " << charMax << " " << hMapFreq[charMax] <<  endl;
            }
            r++;
            //if the total length - frequency of majority element is <= k then that subarray could be selected. 
            //need to figure out how to change the lower limit 
        }
        return maxLength;
    }
};