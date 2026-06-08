#include <bits/stdc++.h>
class Solution {
public:
    // TC -> O(n + m)
    // SC -> O(1)

    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for (auto ch : magazine)
            freq[ch - 'a']++;

        for (auto ch : ransomNote) {
            if (freq[ch - 'a'] == 0)
                return false;

            freq[ch - 'a']--;
        }

        return true;
    }
};

//Problem Link : https://leetcode.com/problems/ransom-note/
