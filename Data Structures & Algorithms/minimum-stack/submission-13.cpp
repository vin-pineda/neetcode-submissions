class MinStack {
public:
    stack<int> minstack;
    stack<int> min;

    void push(int val) {
        minstack.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        }
    }

    void pop() {
        int x = minstack.top();
        minstack.pop();
        if (x == min.top()) min.pop();
    }

    int top() {
        return minstack.top();
    }

    int getMin() {
        return min.top();
    }
};