class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curSum = 0,res = 0;
        unordered_map<int,int> prefSum;
        prefSum[0] = 1;
        for(int num:nums){
            curSum += num;
            int diff = curSum - k;
            res += prefSum[diff];
            prefSum[curSum]++; 
        }
        return res;
    }
};