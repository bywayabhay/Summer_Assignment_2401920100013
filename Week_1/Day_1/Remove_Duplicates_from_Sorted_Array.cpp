class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // TC -> O(n)
        // SC -> O(1)
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                swap(nums[i + 1], nums[j]);
                i++;
                j++;
            }
        }
        return i + 1; // i starts from zero
    }
};

//Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
