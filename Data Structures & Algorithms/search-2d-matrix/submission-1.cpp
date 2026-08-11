class Solution {

int searchRows(vector<vector<int>>& matrix,int target){
    int l = 0;
    int r = matrix.size()-1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(matrix[m][0] == target) return m;
        else if(matrix[m][0] > target){
            r = m-1;
        } 
        else 
            l = m+1;
    }
    return l-1;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //firstly I'll look for the suitable Row using binary search and then we'll use binary search to find the element inside the column
        int searchRow = searchRows(matrix,target);
        if(searchRow < 0) return false; 
        int l = 0;
        int r = matrix[searchRow].size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(matrix[searchRow][m] == target) return true;
            else if(matrix[searchRow][m] > target){
                r = m-1;
            } 
            else 
                l = m+1;
        }
        // cout << searchRow << " " << l << "\n";
        return false;
    }
};
