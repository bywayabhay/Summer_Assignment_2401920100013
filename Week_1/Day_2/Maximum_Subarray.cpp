class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // TC -> O(n)
        // SC -> O(1)
        int n = nums.size();
        int bestEnding = nums[0];
        int maxEnding = nums[0];

        for (int i = 1; i < n; i++) {
            int ch1 = nums[i];
            int ch2 = bestEnding + nums[i];
            bestEnding = max(ch1, ch2);
            maxEnding = max(maxEnding, bestEnding);
        }
        return maxEnding;
    }
};

// Problem Link: https://leetcode.com/problems/maximum-subarray/description/
