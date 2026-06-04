class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // TC -> O(n)
        // SC -> O(1)

        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += mat[i][n - 1 - i];
        }

        // Removing cneter ele if n is odd because centre ele considered in both
        // primary and non-primary diagonal ele
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};

// Problem Link: https://leetcode.com/problems/matrix-diagonal-sum/
