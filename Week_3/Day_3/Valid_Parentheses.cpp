#include <bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        // TC -> O(n)
        // SC -> O(n)

        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            // closing bracket with empty stack
            else if ((ch == ')' || ch == '}' || ch == ']') && st.empty())
                return false;
            else if (ch == ')' && st.top() == '(')
                st.pop();
            else if (ch == '}' && st.top() == '{')
                st.pop();
            else if (ch == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }

        return st.empty();
    }
};

// Problem Link : https://leetcode.com/problems/valid-parentheses/
