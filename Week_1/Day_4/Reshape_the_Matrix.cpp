class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // TC -> O(n * m)
        // SC -> O(r * c)

        int n = mat.size();    // no. of rows
        int m = mat[0].size(); // no. of columns

        vector<vector<int>> reshaped(r, vector<int>(c));

        if (n * m != r * c)
            return mat;

        for (int i = 0; i < r * c; i++) {
            reshaped[i / c][i % c] = mat[i / m][i % m];
        }

        return reshaped;
    }
};

// Problem Link: https://leetcode.com/problems/reshape-the-matrix/
