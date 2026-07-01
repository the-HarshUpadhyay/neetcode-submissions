class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        priority_queue<pair<int,int>> pq;
        for(int r = 0;r<k;r++){
            pq.push(pair<int,int> {nums[r],r});
        }
        vector<int> res;
        res.push_back(pq.top().first);

        //check if max element in the frame, if it is keep it otherwise pop 
        for(int r=k;r<nums.size();r++){
            //insert current element in heap
            pq.push(pair<int,int> {nums[r],r});
            //remove all invalid/out of bound from heap
            while(pq.top().second <= r-k){
                pq.pop();
            }
            //push max element that is guaranteed to be in the limit as we removed all non range elements and only push current element(which is in range/subarray)
            res.push_back(pq.top().first);
        }
        return res;
    }
};
