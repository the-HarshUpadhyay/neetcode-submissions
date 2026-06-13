class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int i=0;i<nums.size();i++){
            nums_set.insert(nums[i]);
        }
        return(nums_set.size() != nums.size());
    }
};