#include <bits/stdc++.h>
class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {}

    void push(int x) {
        // push directly into input stack
        input.push(x);
    }

    int pop() {
        // if output stack is empty, transfer all elements
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int frontElement = output.top();
        output.pop();

        return frontElement;
    }

    int peek() {
        // if output stack is empty, transfer all elements
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

// Problem Link : https://leetcode.com/problems/implement-queue-using-stacks/
