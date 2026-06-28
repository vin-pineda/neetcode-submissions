class MinStack {
public:
    stack<int> minStack;
    stack<int> min;

    MinStack() {}
    
    void push(int val) {
        minStack.push(val);
        if(min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        int top = minStack.top(); minStack.pop();
        if (top == min.top()) min.pop();
    }
    
    int top() {return minStack.top();}
    
    int getMin() {return min.top();}
};
