#include <bits/stdc++.h>
class Solution {
private:
    void findLPS(string s, vector<int>& LPS, int m) {
        int length = 0;
        LPS[0] = 0;
        int i = 1;

        while (i < m) {
            if (s[i] == s[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = LPS[length - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        // TC -> O(n + m)
        // SC -> O(m)
        int n = haystack.length();
        int m = needle.length();

        vector<int> LPS(m, 0);
        findLPS(needle, LPS, m);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};

// Problem Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
