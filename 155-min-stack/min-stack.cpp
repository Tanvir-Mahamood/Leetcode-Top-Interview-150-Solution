class MinStack {
    private:
    vector<vector<int>> STACK;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal;
        if(STACK.empty()) minVal = val;
        else {
            minVal = getMin();
            minVal = min(minVal, val);
        }

        STACK.push_back({val, minVal});
    }
    
    void pop() {
        STACK.pop_back();
    }
    
    int top() {
        return STACK.back()[0];
    }
    
    int getMin() {
        return STACK.back()[1];
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