class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minH;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(const auto& num:nums){
            minH.push(num);
            if(minH.size()>k){
                minH.pop();
            }
        

        }
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size()>k){
            minH.pop();
        }
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */