class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // TC -> O(n) : unordered map is used insertion O(1)
        // SC -> O(n)
        int n = nums.size();
        unordered_map<int, int> mpp; // <ele, cnt>
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > 1)
                return true;
        }
        return false;
    }
};

//Problem Link: https://leetcode.com/problems/contains-duplicate/description/
