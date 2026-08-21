class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()) return "";

        int l = 0;
        int r = timeMap[key].size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            int tStamp = timeMap[key][m].first;
            if(tStamp == timestamp) return timeMap[key][m].second;
            else if(tStamp > timestamp){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return (l==0)?"":timeMap[key][l-1].second;
    }
};
