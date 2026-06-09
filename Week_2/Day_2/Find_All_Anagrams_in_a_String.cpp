#include <bits/stdc++.h>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // TC -> O(n)
        // SC -> O(1)
        int n = s.length();
        int m = p.length();

        vector<int> map(26, 0);
        for (int i = 0; i < m; i++)
            map[p[i] - 'a']++;

        vector<int> result;

        int low = 0;
        int high = 0;

        int k = m;

        while (high < n) {
            if (map[s[high] - 'a'] > 0)
                k--;
            map[s[high] - 'a']--;
            if (high - low + 1 == m) {
                if (k == 0)
                    result.push_back(low);
              
                map[s[low] - 'a']++;

                if (map[s[low] - 'a'] > 0)
                    k++;

                low++;
            }
            high++;
        }

        return result;
    }
};

// Problem Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
