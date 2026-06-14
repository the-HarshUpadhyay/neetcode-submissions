class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hSet(nums.begin(),nums.end());
        int maxCount = 0;
        for(int num:nums){
            if(hSet.find(num-1) == hSet.end()){
                int j = num;
                int counter = 0;
                while(hSet.find(j) != hSet.end()){
                    counter++;
                    j++;
                }
                if(counter>maxCount){
                    maxCount = counter;
                }

            }
            else continue;
        }
        return maxCount;
    }
};
