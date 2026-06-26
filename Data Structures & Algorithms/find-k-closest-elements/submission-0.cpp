class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-1;
        while(l<r){
            if(r-l+1 == k) break;
            if(abs(arr[l] - x) > abs(arr[r] - x)){
                l++;    
            }
            else{
                r--;
            }
        }
        vector<int> res(arr.begin()+l,arr.begin()+r+1);
        cout << l << " " << r;
        return res;
    }
};