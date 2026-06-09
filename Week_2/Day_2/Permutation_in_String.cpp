#include <bits/stdc++.h>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // TC -> O(m)
        // SC -> O(1)
        int n = s1.length();
        int m = s2.length();

        if (n > m)
            return false;

        vector<int> map(26, 0);

        for (int i = 0; i < n; i++)
            map[s1[i] - 'a']++;

        int low = 0;
        int high = 0;

        int k = n;

        while (high < m) {
            if (map[s2[high] - 'a'] > 0)
                k--;

            map[s2[high] - 'a']--;

            if (high - low + 1 == n) {
                if (k == 0)
                    return true;

                if (map[s2[low] - 'a'] >= 0)
                    k++;

                map[s2[low] - 'a']++;
                low++;
            }

            high++;
        }

        return false;
    }
};

// Problem Link : https://leetcode.com/problems/permutation-in-string/
