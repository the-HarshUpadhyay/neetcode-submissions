class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        //for(int i=0;i<n;i++) cout << nums[i] << " "; cout << endl;
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                    if(j>i+1 && j<n-1 && nums[j] == nums[j-1]) continue;
                    long long sum = nums[i] + nums[j];
                    long diffTarget = target-sum;
                    int l=j+1,r=n-1;
                    while(l<r){
                        if(r<n-1 && r>l && nums[r] == nums[r+1]){
                            r--;
                            continue;
                        }
                        if(l>j+1 && l<n-1 && nums[l] == nums[l-1]){
                            l++;
                            continue;
                        }
                        long long diffSum = nums[l] + nums[r];
                        if(diffSum == diffTarget){
                            //cout << i << " " << j << " " << l << " " << r << endl; 
                            res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                            l++;
                            r--;
                        }else if(diffSum > diffTarget){
                            r--;
                        }else{
                            l++;
                        }
                    }
            }
        }
        return res;
    }
};