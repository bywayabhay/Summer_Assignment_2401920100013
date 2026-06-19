#include <bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // TC -> O(n)
        // SC -> O(k)

        int n = nums.size();

        deque<int> dq; // store indices
        vector<int> ans;

        int low = 0;
        int high = 0;

        while (high < n) {
            // remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[high])
                dq.pop_back();

            dq.push_back(high);
            if (dq.front() < low)
                dq.pop_front();

            if (high - low + 1 == k) {
                ans.push_back(nums[dq.front()]);
                low++;
            }
            high++;
        }

        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/sliding-window-maximum/
