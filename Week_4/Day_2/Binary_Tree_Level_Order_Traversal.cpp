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
    vector<vector<int>> lvlOrder(TreeNode* root) {
        vector<vector<int>> lvlOrder;

        // edge case
        if (!root)
            return lvlOrder;

        queue<TreeNode*> q;

        // root
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                lvl.push_back(node->val);
            }

            lvlOrder.push_back(lvl);
        }

        return lvlOrder;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // TC -> O(n)
        // SC -> O(n)

        vector<vector<int>> ans = lvlOrder(root);

        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/binary-tree-level-order-traversal/
