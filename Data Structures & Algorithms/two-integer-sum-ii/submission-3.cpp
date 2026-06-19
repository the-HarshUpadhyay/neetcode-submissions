class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int sum = nums[l] + nums[r];
            
            if(sum < target){
                l++;
            }else if(sum > target){
                r--;
            }else{
                break;
            } 
        }
        vector<int> res = {l+1,r+1};
        return res;
    }
};