#include <bits/stdc++.h>
class Solution {
private:
    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st; // store indices
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop(); // maintain monotonic increasing stack
            }

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();

        stack<int> st; // store indices
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop(); // maintain monotonic increasing stack
            }

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        // TC -> O(n)
        // SC -> O(n)

        int n = heights.size();
        int largestArea = 0;

        vector<int> PSE = findPSE(heights);
        vector<int> NSE = findNSE(heights);

        for (int i = 0; i < n; i++) {
            int width = NSE[i] - PSE[i] - 1; // (r - l - 1)
            int area = heights[i] * width;

            largestArea = max(largestArea, area);
        }

        return largestArea;
    }
};

// Problem Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
