class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int idx = 0;
        int n = nums.size();
        vector<int> copyArr{nums.begin(),nums.end()};
        for(int i=0;i<n;i++){
            idx = (i+k)%n;
            nums[idx] = copyArr[i];
        }
    }
};