class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while(l<=r){
            int m = l + (r-l)/2;
            if(x/m == m) return m;
            else if(x/m > m) l = m+1;
            else r = m-1; 
        }
        return r;
    }
};