//Memory Limit Exceeded, I don't know why
//
//learn to use stack
class MinStack {
public:
    stack<int> data;
    stack<int> minData;

    void push(int x) {
        data.push(x);

        if (minData.empty())
            minData.push(x);
        else
            minData.push(min(x, minData.top()));
        return;
    }

    void pop() {
        data.pop();
        minData.pop();
        return;
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minData.top();
    }
};

