#include <bits/stdc++.h>
class Solution {
public:
    // TC -> O(n)
    // SC -> O(1)

    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m)
            return false;

        vector<int> counts(26, 0);

        for (int i = 0; i < n; i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for (auto it : counts) {
            if (it != 0)
                return false;
        }

        return true;
    }
};

//Problem Link : https://leetcode.com/problems/valid-anagram/
