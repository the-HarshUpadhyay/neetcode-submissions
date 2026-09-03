class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //floyd's cycle detection
        int slowptr = 0;
        int fastptr = 0;
        do{   
            slowptr = nums[slowptr];
            fastptr = nums[nums[fastptr]];
        }while(slowptr != fastptr);
        slowptr = 0;
        while(slowptr!=fastptr){
            slowptr = nums[slowptr];
            fastptr = nums[fastptr];
        }
        
        return fastptr;
    }
};
