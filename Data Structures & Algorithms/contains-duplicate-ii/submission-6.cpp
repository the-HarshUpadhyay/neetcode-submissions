class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hSet;
        int l = 0;
        int n = nums.size();
        for(int r=0;r<n;r++){
            // cout << l << " " << r << endl;
            if(r-l > k){
                hSet.erase(nums[l]);
                l++;
            }
            if(hSet.find(nums[r]) != hSet.end()) return true;
            hSet.insert(nums[r]);
            cout << l << " " << r << endl;

        }
        return false;
    }
};