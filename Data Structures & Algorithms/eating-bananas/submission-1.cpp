class Solution {

public:
    int hours(vector<int>& piles,int h){
        int hours = 0;
        for(int pile:piles){
            hours += ceil((double)pile/h);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = INT_MAX;
        int l = 1;
        while(l<=r){
            int m = l + (r-l)/2;
            int nh = hours(piles,m);
            if(nh <= h) r = m-1;
            else if(nh > h) l = m +1;
        }
        return l;
    }
};