class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        vector<vector<int>> res;
        for(a=0;a<nums.size();a++){
            int targetSum = 0 - nums[a];
            int b=a+1;
            int c=nums.size()-1;
            outer:
            while(b<c){
                int sum = nums[b] + nums[c];
                if(nums[b] + nums[c] == targetSum){
                    bool isDuplicate = false;
                    vector<int> v = {nums[a],nums[b],nums[c]};
                    for(const auto &it: res){
                        int x = it[0],y=it[1];
                        if(x==nums[a] && y==nums[b]) isDuplicate = true;
                    }
                    if(!isDuplicate){
                        res.push_back(v);
                    }
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
