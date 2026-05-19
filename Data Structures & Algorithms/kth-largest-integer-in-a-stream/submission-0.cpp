class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int limit=0;

    KthLargest(int k, vector<int>& nums) {
        limit=k;
        for(int i : nums){
          minHeap.push(i);
        }
        while(minHeap.size()>k){
            minHeap.pop();
        }
    }
    
    int add(int val) {
        if(minHeap.size()==limit && minHeap.top()<val){
            minHeap.pop();
            minHeap.push(val);
        } 
        else if(minHeap.size()<limit){
            minHeap.push(val);
        }

        return minHeap.top();
    }
};
