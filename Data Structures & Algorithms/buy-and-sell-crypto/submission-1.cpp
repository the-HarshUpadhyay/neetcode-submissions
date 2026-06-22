class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minI = INT_MAX;
        int mxProfit = INT_MIN;
        for(int i=0;i<n;i++){
            int profit = max(0,prices[i]-minI);
            minI = min(minI,prices[i]);
            mxProfit = max(profit,mxProfit);
        }
        return mxProfit;
    }
};
