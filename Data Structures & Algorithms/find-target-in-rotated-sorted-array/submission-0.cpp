class Solution {
public:
    int findStartIdx(vector<int>& nums){
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m] < nums[r]){
                r = m;
            }else {
                l = m+1; 
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int offset = findStartIdx(nums);
        int l = 0;
        int r = nums.size()-1;
        int n = nums.size();
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[(m+offset)%n] == target) return (m+offset)%n;
            else if(nums[(m+offset)%n] > target){
                r = m-1;
            }
            else l = m+1;
        }
        return -1;
    }
};
