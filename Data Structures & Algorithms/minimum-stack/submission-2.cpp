class MinStack {
private:
stack<int> min;
stack<int> minStack;
public:
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int val) {
        minStack.push(val);
        if(val <= min.top()) 
        {
            min.push(val);
        }
    }
    
    void pop() {
        if(min.top() == minStack.top())
        {
            min.pop();
        }
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
