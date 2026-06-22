class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        int maxH = 0;
        int vol = 0;
        vector<int> lBoundary(n,0);
        //front sweep to calculate left highest boundary/wall
        for(int i=1;i<n;i++){
            maxH = max(height[i-1],maxH);
            lBoundary[i] = maxH;
        }

        // for(int i:lBoundary) cout << i << " "; cout << endl;
        maxH = 0;
        vector<int> rBoundary(n,0);
        //back sweep to calculate right highest boundary/wall
        for(int i=n-2;i>=0;i--){
            maxH = max(height[i+1],maxH);
            rBoundary[i] = maxH;
        }
        // for(int i:rBoundary) cout << i << " "; cout << endl;
        //now we need to calculate the vol. of water to be filled, which would be 
        // min(lBoundary[i],rBoundary[i]) - height[i]
        for(int i=0;i<n;i++){
            int volH = max(0,min(lBoundary[i],rBoundary[i]) - height[i]);
            // cout << volH << " ";
            vol += volH;
        }
        cout << endl;

        
        return vol;
    }
};
