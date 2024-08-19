class StockSpanner {
    stack<pair<int,int>> s;
    int idx;
public:
    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
        idx++;
        while(!s.empty()&&s.top().first<=price){
            s.pop();
        
        }
        int ans=idx-(s.empty()?-1:s.top().second);
        s.push({price,idx});
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */