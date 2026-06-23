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
    vector<int> inorderTraversal(TreeNode* root) {
        // TC -> O(n)
        // SC -> O(1)

        vector<int> inorder;

        TreeNode* curr = root;

        while (curr != nullptr) {
            // agar curr->left null hai to print ans
            if (curr->left == nullptr) {
                // store
                inorder.push_back(curr->val);

                // go to right
                curr = curr->right;
            } else {
                // left subtree pr jao (L, N, R)
                TreeNode* leftChild = curr->left;

                // iss left subchild se rightmost me jao
                while (leftChild->right != nullptr &&
                       leftChild->right != curr) {
                    leftChild = leftChild->right;
                }

                // right is null meaning there is no link
                if (leftChild->right == nullptr) {
                    // make link
                    leftChild->right = curr;

                    // move curr to left
                    curr = curr->left;
                } else {
                    // we traverse it break the link
                    leftChild->right = nullptr;

                    inorder.push_back(curr->val);

                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};

// Problem Link : https://leetcode.com/problems/binary-tree-inorder-traversal/
