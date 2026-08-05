class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();

        vector<int> stk;
        vector<pair<int,int>> sortedData;

        //sort both the vectors based on initial position because cars which are slower and behind faster cars can never catch up
        for(int i=0;i<n;i++){
            sortedData.push_back({position[i],speed[i]});
        }
        sort(sortedData.begin(),sortedData.end());

        for (int i = 0; i < n; i++) {
            //maintain a time array where all lesser time can be clubbed with more time
            while(!stk.empty() && static_cast<float>(target-sortedData[i].first)/sortedData[i].second >= static_cast<float>(target - sortedData[stk.back()].first)/(sortedData[stk.back()].second)){
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return stk.size();
    }
};
