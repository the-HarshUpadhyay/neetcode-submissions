class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            cout << l << " " << r << " " << m << endl;

            if(m!=l && nums[m] == nums[l]){ 
                l++;             
                continue;
            }
            if(m!=r && nums[m] == nums[r]){ 
                r--; 
                continue;
            }

            if(nums[m] == target) return true;
            if(nums[l] <= nums[m]){ // left subarray is sorted
                if(target >= nums[l] && target < nums[m]) {//target withing sorted subarray
                    r = m-1;
                }
                else l = m+1;
            }
            else {//right subarray is sorted
                if(target > nums[m] && target <= nums[r]){
                    l = m+1;
                }
                else r = m-1;
            }
        }
        return false;
    }
};