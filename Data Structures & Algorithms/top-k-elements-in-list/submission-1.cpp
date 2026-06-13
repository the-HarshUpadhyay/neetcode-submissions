class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;
        for(int num:nums){
            hmap[num]++;
        }
        vector<pair<int,int>> arr;
        for(const auto& p: hmap){
            arr.push_back({p.second,p.first});
        }
        vector<int> res;
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<k;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
