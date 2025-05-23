class MinStack {
    std::stack<long long> st;   // ❶ wider type
    long long mini;             // ❶ wider type
public:
    MinStack() : mini(LLONG_MAX) {}  // <climits> for LLONG_MAX

    void push(int val) {
        long long x = val;            // promote once
        if (st.empty()) {
            mini = x;
            st.push(x);
        } else {
            if (x < mini) {
                st.push(2LL * x - mini);  // ❷ safe: 2LL forces 64-bit
                mini = x;
            } else {
                st.push(x);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long top = st.top(); st.pop();
        if (top < mini) mini = 2 * mini - top;   // still 64-bit
        if (st.empty()) mini = LLONG_MAX;
    }

    int top() {
        if (st.empty()) return -1;
        long long top = st.top();
        return static_cast<int>(top < mini ? mini : top);
    }

    int getMin() {
        return st.empty() ? -1 : static_cast<int>(mini);
    }
};
