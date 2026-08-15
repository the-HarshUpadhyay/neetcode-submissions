class Solution {
public:
    bool isValid(int m,vector<int>& weights,int days){
        int daysR = 1;
        int sum = 0;
        for(int weight:weights){
            if(sum + weight > m){
                sum = weight;
                daysR++;
            }
            else sum += weight;
        }
        return (daysR <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = INT_MAX;
        while(l<=r){
            int m = l + (r-l)/2;
            if(isValid(m,weights,days)) r = m-1;
            else l = m + 1;
        }
        return l;
    }
};