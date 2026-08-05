class Solution {
public:
    string simplifyPath(string path) {
        vector<string> simplePath;
        int i = 0;
        while(path[i] != '\0'){
            if(path[i] == '/'){
                i++;
                continue;
            }
            string word = "";
            while(path[i] != '/' && path[i] != '\0'){
                word += path[i++];
            }

            if(word != ""){
                if(!simplePath.empty() && word == "..") simplePath.pop_back();
                else if(simplePath.empty() && word == "..") continue;
                else if(word == ".") continue;
                else simplePath.push_back(word);
            }
        }
        string res ="";
        for(string s: simplePath){
            res += "/" + s;
        }
        return (res=="")?"/":res;
    }
};