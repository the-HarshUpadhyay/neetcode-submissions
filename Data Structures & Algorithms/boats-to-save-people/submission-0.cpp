class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size()-1;
        int res = 0;
        sort(people.begin(),people.end());
        //for(int person: people) cout << person << " "; cout << endl;
        int soloCnt = 0;
        // we need to pair the heaviest and lightest people together, if their combined weight is heavier than limit, then we'll ship the heavier person solo.
        while(l<r){
            res++;
            //cout << l << " " << r << " RES: "<<  res <<  endl ;
            int sum = people[l] + people[r];
            if(sum <= limit){
                l++;r--;
            } else {
                soloCnt++;
                r--;
            }
        }
        //if after shipping all the pairs and solos, the no. of people is odd then one person ought to not form a pair, hence we'll ship that person solo
        if((people.size() - soloCnt)%2) res++;
        return res;
    }
};