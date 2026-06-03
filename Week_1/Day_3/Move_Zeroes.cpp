class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();
        int i = 0; // position to place non-zero elements
        int j = 0; // traversal pointer

        while (j < n) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
                j++;
            } else {
                j++;
            }
        }

        while (i < n) {
            nums[i] = 0;
            i++;
        }
    }
};

// Problem Link: https://leetcode.com/problems/move-zeroes/
