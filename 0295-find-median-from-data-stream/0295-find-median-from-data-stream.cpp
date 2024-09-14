class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(maxH.empty() || num <= maxH.top()) {
            maxH.push(num);
        } else {
            minH.push(num);
        }
        
        // Balancing the heaps: maxH can have at most one extra element more than minH
        if(maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } else if(minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        int n=minH.size()+maxH.size();
        if(n%2!=0){
            return maxH.top();
        }else{
            return (double)(maxH.top()+minH.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */