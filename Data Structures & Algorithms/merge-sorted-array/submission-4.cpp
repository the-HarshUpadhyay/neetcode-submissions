class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                //shift rest of nums1 to the right to make space for nums2[j];  
                int k = i+1;
                int curr=0,prev = nums1[i];
                while(k<=m){
                    curr = nums1[k];
                    nums1[k] = prev;
                    prev = curr;
                    k++;
                }
                nums1[i] = nums2[j];
                j++;
                m++;
            }
            i++;
        }
        while(j<n){
            nums1[i++] = nums2[j++];
        }
    }
};