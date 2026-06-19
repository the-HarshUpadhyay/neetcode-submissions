class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        vector<vector<int>> res;
        for(a=0;a<nums.size();a++){
            if(a>0 && nums[a] == nums[a-1]) continue;
            int targetSum = 0 - nums[a];
            int b=a+1;
            int c=nums.size()-1;
            while(b<c){
                if(b>a+1 && nums[b] == nums[b-1]) {b++; continue;}
                int sum = nums[b] + nums[c];
                if(nums[b] + nums[c] == targetSum){
                    vector<int> v = {nums[a],nums[b],nums[c]};
                    res.push_back(v);
                    b++;c--;
                }else if(sum > targetSum){
                    c--;
                }else{
                    b++;
                }
            }
        }
        return res;
    }
};
