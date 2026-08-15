class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums[l] <= nums[r]) return nums[l];
        while(l<r){
            int m = l + (r-l)/2;
            cout << l <<  " " << r << endl; 

            //always chase the point where array breaks monotonicity
            if(nums[m] < nums[r]){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return nums[l];
    }
};
