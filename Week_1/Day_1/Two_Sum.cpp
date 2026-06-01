#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TC -> O(n)
        //  SC -> O(n)
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int moreNeeded = target - nums[i];
            if (mpp.find(moreNeeded) == mpp.end()) {
                mpp[nums[i]] = i;
            } else {
                return {mpp[moreNeeded], i};
            }
        }
        // dummy return
        return {-1, -1};
    }
};

//Problem Link : https://leetcode.com/problems/two-sum/
