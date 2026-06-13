class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> countNums;
        for(int i=0;i<nums.size();i++){
            countNums[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            if(countNums.count(target-nums[i])){
                if(i==countNums[target-nums[i]]) continue;
                return vector<int> {i,countNums[target-nums[i]]};
            }
        }
    }
};
