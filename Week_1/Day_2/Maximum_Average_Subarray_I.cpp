class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // TC -> O(n)
        // SC -> O(1)

        // Fixed Window Problem
        int n = nums.size();
        int low = 0;
        int high = 0;
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxSum = sum;
        for (int i = k; i < n; i++) {
            // substract left element of window and add right element of window
            sum += nums[i] - nums[i - k];

            // update maxSum
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};

// Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/
