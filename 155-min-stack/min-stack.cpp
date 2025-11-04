class MinStack {
private:
    stack<int> stck;
    stack<int> minStck;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stck.push(val);
        if (minStck.empty() || val <= minStck.top()) {
            minStck.push(val);
        }
    }
    
    void pop() {
        if (stck.top() == minStck.top()) {
            stck.pop();
            minStck.pop();
        } else {
            stck.pop();
        }
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minStck.top();
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