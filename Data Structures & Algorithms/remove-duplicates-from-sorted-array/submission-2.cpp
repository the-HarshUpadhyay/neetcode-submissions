class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int counter= min(1,n);
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[counter++] = nums[i];
            }
        }
        return counter;
    }
};