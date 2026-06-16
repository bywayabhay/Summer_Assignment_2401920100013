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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC -> O(n)
        // SC -> O(1)

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        // edge case
        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        return head;
    }
};

// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
