class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        int vol=0;
        int l = 0,r= n-1;
        int leftMax = height[l],rightMax=height[r];
        
        while(l<r){
            int volH =0;
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax,height[l]);
                volH = leftMax - height[l];
            }else{
                r--;
                rightMax = max(rightMax,height[r]);
                volH = rightMax - height[r];
            }
            vol += volH;
        }
        return vol;
    }
};
