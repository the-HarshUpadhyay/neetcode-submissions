class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        vector<vector<int>> res;
        while(a<nums.size()){
            int targetSum = 0 - nums[a];
            int b=a+1;
            int c=nums.size()-1;
            while(b<c){
                int sum = nums[b] + nums[c];
                if(sum == targetSum){
                    vector<int> v = {nums[a],nums[b],nums[c]};
                    res.push_back(v);
                    c--;
                }else if(sum > targetSum){
                    c--;
                    continue;
                }
                b++;
                while(b<c && nums[b] == nums[b-1]) b++;
            }
            a++;
            while(a<nums.size() && nums[a] == nums[a-1]) a++;
        }
        return res;
    }
};
