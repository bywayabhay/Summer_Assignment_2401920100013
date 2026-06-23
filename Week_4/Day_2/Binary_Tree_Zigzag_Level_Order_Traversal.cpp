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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // TC -> O(n)
        // SC -> O(n)

        vector<vector<int>> ans;

        // edge case
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                int idx = leftToRight ? i : size - i - 1;
                level[idx] = currNode->val;

                if (currNode->left)
                    q.push(currNode->left);

                if (currNode->right)
                    q.push(currNode->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
