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
private:
    ListNode* reverseLL(ListNode* head) {
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

public:
    bool isPalindrome(ListNode* head) {
        // TC -> O(n)
        // SC -> O(1)

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLL(slow->next);
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while (temp2 != nullptr) {
            if (temp2->val != temp1->val) {
                reverseLL(slow->next);
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        reverseLL(slow->next);
        return true;
    }
};

// Problem Link : https://leetcode.com/problems/palindrome-linked-list/
