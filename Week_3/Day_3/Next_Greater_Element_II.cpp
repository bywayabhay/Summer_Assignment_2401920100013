#include <bits/stdc++.h>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // TC -> O(2n)
        // SC -> O(n)

        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int ind = i % n;

            while (!st.empty() && st.top() <= nums[ind])
                st.pop();

            // calculate NGE only for the original array
            if (i < n) {
                if (!st.empty())
                    ans[i] = st.top();
            }

            // push current element into the stack
            st.push(nums[ind]);
        }

        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/next-greater-element-ii/
