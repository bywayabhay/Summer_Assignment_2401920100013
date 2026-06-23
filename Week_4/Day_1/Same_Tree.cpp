#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool isSame(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (!q && p))
            return false;

        if (!p && !q)
            return true;

        if (p->val != q->val)
            return false;

        bool left = isSame(p->left, q->left);
        bool right = isSame(p->right, q->right);

        return left && right;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // TC -> O(n)
        // SC -> O(h)

        return isSame(p, q);
    }
};

// Problem Link : https://leetcode.com/problems/same-tree/
