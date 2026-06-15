class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> hMap;
        for(int num:nums){
            hMap[num]++;
        }
        vector<int> res;
        for(const auto&     it:hMap){
            if(it.second > n/3){
                res.push_back(it.first);
            }
        }
        return res;
    }
};