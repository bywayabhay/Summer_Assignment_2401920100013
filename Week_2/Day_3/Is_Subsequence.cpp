#include <bits/stdc++.h>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // TC -> O(n + m)
        // SC -> O(1)

        int n = s.length();
        int m = t.length();

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == n;
    }
};

// Problem Link : https://leetcode.com/problems/is-subsequence/
