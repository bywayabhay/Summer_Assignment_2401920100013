#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // TC -> O(n)
        // SC -> O(1)

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};

// Problem Link : https://leetcode.com/problems/reverse-linked-list/
