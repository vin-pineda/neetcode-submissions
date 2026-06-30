class MinStack {
public:
    stack<int> main;
    stack<int> min;

    MinStack() {}
    
    void push(int val) {
        main.push(val);
        if(min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        int top = main.top();
        main.pop();
        if (top == min.top()) min.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min.top();
    }
};
