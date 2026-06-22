class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int l=0;l<n-1;l++){
            for(int r=l+1;r<=l+k;r++){
                if(!(r<n)) break;
                // cout << "l: "<< l << " r: " << r << " nums[l]: " << nums[l] << " nums[r]: " << nums[r] << endl;
                if(nums[l] == nums[r]) return true;
            } 
        }
        return false;
    }
};