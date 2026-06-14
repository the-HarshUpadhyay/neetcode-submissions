class Solution {
   private:
    int noOfWords;
    vector<int> strIdx = vector<int>(100, 0);

   public:
    string encode(vector<string>& strs) {
        noOfWords = strs.size();
        if(noOfWords == 0) return "";
        string s = strs[0];
        for (int i = 1; i < noOfWords; i++) {
            strIdx[i] = strIdx[i - 1] + strs[i-1].size();
            s += strs[i];
        }
        strIdx[noOfWords] = strIdx[noOfWords - 1] + strs[noOfWords - 1].size();
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs(noOfWords);
        for (int i = 0; i < noOfWords; i++) {
            strs[i] = s.substr(strIdx[i], strIdx[i + 1] - strIdx[i]);
        }
        return strs;
    }
};
