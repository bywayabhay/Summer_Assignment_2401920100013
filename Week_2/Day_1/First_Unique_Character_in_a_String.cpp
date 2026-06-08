#include <bits/stdc++.h>
class Solution {
public:
    // TC -> O(n)
    // SC -> O(1)

    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int idx = -1;

        for (auto it : s)
            freq[it - 'a']++;

        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};

//Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/
