class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<10001> bitset;
        for(int num:nums){
            if(bitset.test(num)) return num;
            else bitset.set(num);
        }
        return -1;
    }
};
