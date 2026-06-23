#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

public:
    int maxDepth(TreeNode* root) {
        // TC -> O(n)
        // SC -> O(h)

        return height(root);
    }
};

// Problem Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
