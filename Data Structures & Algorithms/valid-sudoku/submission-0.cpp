class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check every row & use hashmap to keep count
        unordered_map<char,int> hMap;
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                hMap[board[i][j]]++;
                if((hMap[board[i][j]]) > 1) return false;
            }
            hMap.clear();
        }
        //check every column
        //cout << "Checking EVERY ROW" << endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                hMap[board[i][j]]++;
                if((hMap[board[i][j]]) > 1) return false;
            }
            hMap.clear();
        }
        //check every block
        for(int i=0;i<9;i++){
            int a = 3 * (i/3);
            int b = 3 * (i%3);
            for(int p = a;p<a+3;p++){
                for(int q=b;q<b+3;q++){
                    if(board[p][q] == '.') continue;
                    hMap[board[p][q]]++;
                    if((hMap[board[p][q]]) > 1) return false;
                }
            }
            hMap.clear();
        }
        return true;
    }
};
