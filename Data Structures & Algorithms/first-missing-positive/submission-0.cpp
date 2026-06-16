class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int posMin = 1;
        unordered_set<int> hSet;
        for(int num:nums){
            hSet.insert(num);
        }
        for(int i=1;;i++){
            if(hSet.find(i) == hSet.end()) return i;
        }
    }
};