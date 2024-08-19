class MinStack {
    stack<long long> s;
    long long minE;
public:
    MinStack() {
        minE=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()) s.push(val),minE=val;
        else{
            if(val>minE) s.push(val);
            else{
                long long v=2LL*val-minE;
                minE=val;
                s.push(v);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        else{
            long long val=s.top();
            s.pop();
            if(val>minE) return;
            else{
                 minE=2*minE-val;
            }
        }
        
    }
    
    int top() {
        long long val=s.top();
        if(val>minE) return val;
        else return minE;
    }
    
    int getMin() {
        return minE;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */