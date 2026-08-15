class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums[l] <= nums[r]) return nums[l];
        while(l<r){
            int m = l + (r-l)/2;
            cout << l <<  " " << r << endl; 

            if(m>0 && nums[m-1] > nums[m]) return nums[m];
            //always chase the point where array breaks monotonicity
            if(nums[l] > nums[m]){
                r = m-1;
            }
            else if(nums[l] < nums[r]) r = m-1;
            else{
                l = m+1;
            }
        }
        return nums[l];
    }
};
