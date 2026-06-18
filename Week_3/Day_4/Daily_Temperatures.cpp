#include <bits/stdc++.h>
#define temperatures nums

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // TC -> O(n)
        // SC -> O(n)

        // monotonic decreasing stack
        int n = nums.size();

        vector<int> ans(n, 0);
        stack<int> st; // store indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop(); // we want to maintain decreasing stack
            }

            // store answer
            if (!st.empty())
                ans[i] = st.top() - i;

            st.push(i);
        }

        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/daily-temperatures/
