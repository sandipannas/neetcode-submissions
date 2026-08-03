class MinStack {
public:
    stack<int> stk;
    stack<int> stkmin;

    MinStack() {}

    void push(int value) {
        if ( stk.empty() || value<=stkmin.top() )  stkmin.push(value);
        stk.push(value);
    }

    void pop() { 
        if(stkmin.top()==stk.top()){ stkmin.pop(); }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return stkmin.top(); }
};
