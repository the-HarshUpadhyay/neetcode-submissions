class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        unordered_map<int,int> hashSet;
        for(int i=0;i<numbers.size();i++){
            hashSet[numbers[i]] = i+1;
            int reqElement = target - numbers[i];
            if(reqElement == numbers[i]) continue;
            if(hashSet[reqElement]){
                res[0] = min(i+1,hashSet[reqElement]);
                res[1] = max(i+1,hashSet[reqElement]);
                break;
            } 
        }
        return res;
    }
};
