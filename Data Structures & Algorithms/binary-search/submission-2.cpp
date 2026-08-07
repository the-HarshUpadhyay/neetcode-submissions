class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        if(lo == hi) return (target == nums[lo])?lo : -1; 
        while(lo<=hi){
            int m = (hi - lo)/2 + lo;
            if(nums[m] < target){
                lo = m+1;
            }
            else if(nums[m] > target){
                hi = m-1;
            }
            else if(nums[m] == target){
                return m;
            }
            cout << lo << " " << hi << " " << m << endl;
        }
        return -1;
    }
};
