class NumMatrix {
private:

    vector<vector<int>> s;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        for(int i=0;i<=n;i++){
            s.push_back(vector<int> (m+1));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s[i+1][j+1] = matrix[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];
                //cout << sumArr[i+1][j+1] << " ";
            }
            //cout << endl;
        }

    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        //adjusting query's 0 based indexing according to our 1 based prefix sum;
        r1++;r2++;c1++;c2++;
        int ans = s[r2][c2] - (s[r2][c1-1] + s[r1-1][c2] - s[r1-1][c1-1]);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */