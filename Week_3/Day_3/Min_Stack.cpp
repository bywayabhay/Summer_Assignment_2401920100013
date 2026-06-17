#include <bits/stdc++.h>
class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    // TC -> O(1) for all operations
    // SC -> O(n)

    // empty constructor
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            mini = value;
            st.push(value);
            return;
        }

        if (value > mini)
            st.push(value);
        else {
            // add modified value
            long long mValue = 2LL * value - mini;
            st.push(mValue);
            mini = value;
        }
    }

    void pop() {
        // if stack is empty
        if (st.empty())
            return;

        // get the modified top
        long long X = st.top();
        st.pop();

        // update mini
        if (X < mini) {
            mini = 2LL * mini - X;
        }
    }

    int top() {
        // if stack is empty
        if (st.empty())
            return -1;

        // get the modified top
        long long X = st.top();

        if (mini < X)
            return X;
        else
            return mini;
    }

    int getMin() {
        return mini;
    }
};

// Problem Link : https://leetcode.com/problems/min-stack/
