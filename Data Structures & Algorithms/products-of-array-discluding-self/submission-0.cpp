class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        //prefixProd[i] incl. prod of all elements 0..i-1;
        //suffixProd[i] incl. prod of all elements i+1..n-1;

        vector<int> prefixProd(n,1);
        vector<int> suffixProd(n,1);
        suffixProd[n-2] = nums[n-1];
        prefixProd[1] = nums[0];
        
        for(int i=2;i<n;i++){
            prefixProd[i] = nums[i-1] * prefixProd[i-1];
        }
        for(int j=n-3;j>=0;j--){
            suffixProd[j] = nums[j+1] * suffixProd[j+1];
        }
        for(int i=0;i<n;i++){
            cout << "Suff: " << suffixProd[i] << " Pref: " << prefixProd[i] << endl; 
        }

        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i] = suffixProd[i] * prefixProd[i];
        }
        return res;
    }
};
