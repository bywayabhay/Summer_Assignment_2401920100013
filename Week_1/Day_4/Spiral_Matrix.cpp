class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // TC -> O(m * n)
        // SC -> O(1) (excluding output array)

        int m = matrix.size();    // no. of rows
        int n = matrix[0].size(); // no. of cols

        int top = 0;
        int left = 0;
        int bottom = m - 1;
        int right = n - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // from top to bottom
            if (top <= bottom) {
                for (int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
            }
            right--;

            // from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;

            // from bottom to top
            if (top <= bottom && left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }

        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/spiral-matrix/
