class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(nums.size()+1,0);
        for(int i=1;i<=n;i++){
            int sum = prefixSum[i-1] + nums[i-1];
            prefixSum[i] = sum;
        }
        int l = 0;
        int r = 1;
        int res = INT_MAX;
        while(l<=r && l<=n && r <= n){
            //cout << l << " " << r << " presum " << prefixSum[l] << " " << prefixSum[r] << endl;
            //the prefix Sum array is non decreasing , converts the problem from sliding window to two pointer approach

            //shrink to find the minimum subarray if we found the array 
            if((prefixSum[r] - prefixSum[l]) >= target){
                res = min(res,r-l);
                l++;
            }
            //expand if the minimum condition doesn't meet
            else{
                r++;
            }
        }
        return res==INT_MAX?0:res;
    }
};