class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int maxArea = INT_MIN;
        while(l<r){
            int area = min(arr[l],arr[r]) * (r-l);
            maxArea = max(maxArea,area);
            if(arr[l] > arr[r]) r--;
            else l++;
        }
        return maxArea;
    }
};
