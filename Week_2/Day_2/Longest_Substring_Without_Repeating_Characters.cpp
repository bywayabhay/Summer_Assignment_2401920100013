#include <bits/stdc++.h>
class Solution {
public:
    // TC -> O(n)

    // SC -> O(min(n, charset))
    // charset means the total number of possible distinct characters that can appear in the string.

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int low = 0;
        int high = 0;

        unordered_map<char, int> mpp; // char -> freq

        while (high < n) {
            mpp[s[high]]++;
            int currWindowLength = high - low + 1;

            while (mpp.size() < currWindowLength) {
                mpp[s[low]]--;

                if (mpp[s[low]] == 0)
                    mpp.erase(s[low]);

                low++;

                currWindowLength = high - low + 1;
            }

            int len = high - low + 1;
            maxLen = max(len, maxLen);

            high++;
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};

//Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
