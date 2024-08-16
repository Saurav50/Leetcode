class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int top;
    MyQueue() {
        top=-1;
    }
    
    void push(int x) {
        s1.push(x);
        if(s1.size()==1) top=x;
    }
    
    int pop() {
        if(s1.empty()) return -1;
        while(!s1.empty()){
            int temp=s1.top();
            s1.pop();
            s2.push(temp);
        }
        int ele=s2.top();
        s2.pop();
        if(!s2.empty())top=s2.top();
        while(!s2.empty()){
            int temp=s2.top();
            s2.pop();
            s1.push(temp);
        }
        return ele;

    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */