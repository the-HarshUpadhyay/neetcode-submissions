class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int moved = 0;
        int prev = nums[0];
        //inplace cyclic rotation
        for(int i=0;moved<n;i++){
            int curr = i;
            int prev = nums[i];
            do{
                int nextIdx = (curr + k)%n;
                swap(prev,nums[nextIdx]);
                curr = nextIdx;
                moved++;
            }while(i != curr);
        }
    }
};