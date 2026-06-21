class Solution {
public:
    int maxArea(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
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
