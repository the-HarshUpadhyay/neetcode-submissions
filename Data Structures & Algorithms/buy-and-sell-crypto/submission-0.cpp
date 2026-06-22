class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l=0,r=n-1;
        int profit = 0;
        vector<int> minI(n,0);
        vector<int> maxI(n,0);
        minI[0] = prices[0]; 
        for(int i=1;i<n;i++){
            minI[i] = min(minI[i-1],prices[i]);
        }
        maxI[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxI[i] = max(maxI[i+1],prices[i]);
        }
        int mxProfit = INT_MIN;
        for(int i=0;i<n;i++){
            profit = maxI[i] - minI[i];
            mxProfit = max(mxProfit,profit);
        }
        return mxProfit;
    }
};
