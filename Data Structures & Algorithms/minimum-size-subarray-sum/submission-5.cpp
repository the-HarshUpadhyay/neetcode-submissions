class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        //vector<int> prefixSum(nums.size()+1,0);
        //for(int i=1;i<=n;i++){
            // int sum = prefixSum[i-1] + nums[i-1];
            // prefixSum[i] = sum;
        //}
        int prefr = nums[0];
        int prefl = 0;
        int l = 0;
        int r = 1;
        int res = INT_MAX;
        while(l<=r && r <= n){
            //cout << l << " " << r << " presum " << prefl << " " << prefr << endl;
            //the prefix Sum array is non decreasing , converts the problem from sliding window to two pointer approach

            //shrink to find the minimum subarray if we found the array 
            if(prefr - prefl >= target){
                res = min(res,r-l);
                if(l<n)prefl += nums[l];
                l++;
            }
            //expand if the minimum condition doesn't meet
            else{
                if(r<n)prefr += nums[r];
                r++;
            }
        }
        return res==INT_MAX?0:res;
    }
};