class MyStack {
    queue<int> q;
    int peek;
    int s;
public:
    MyStack() {
        peek=-1;
        s=0;
    }
    
    void push(int x) {
        q.push(x);
        peek=x;
        s++;
    }
    
    int pop() {
        if(q.empty()) return -1;
        int i=s;
        while(i>1){
            int ele=q.front();
            q.pop();
            i--;
            q.push(ele);
        }
        
        int ans= q.front();
        q.pop();
        peek=q.back();
        s--;
        return ans;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */