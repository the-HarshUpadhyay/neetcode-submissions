class Solution {
public:
    void heapify(vector<pair<int,int>>& arr,int n,int i){
        int smallest = i;
        int l = 2*i +1;
        int r = 2*i + 2;

        if(l<n && arr[smallest].first > arr[l].first){
            smallest = l;
        }
        if(r<n && arr[smallest].first > arr[r].first){
            smallest = r;
        }
        if(smallest != i){
            swap(arr[smallest],arr[i]);
            heapify(arr,n,smallest);
        }
    }

    void heapSort(vector<pair<int,int>>& arr){
        int n = arr.size();

        for(int i= n/2 -1;i>=0;i--){
            heapify(arr,n,i);
        }

        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fmap;
        for(int num:nums) fmap[num]++;
        vector<pair<int,int>> min_heap;
        for(const auto it:fmap){
            min_heap.push_back({it.second,it.first});
        }
        //min_heap.first -> freq
        //second -> element
        heapSort(min_heap);
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(min_heap[i].second);
        }
    return res;
    }
};
