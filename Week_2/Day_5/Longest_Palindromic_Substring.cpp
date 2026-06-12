class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        // TC -> O(n^3)
        // SC -> O(1)

      //optimisation needs DP and Manacher's Algorithm → O(n) (advanced) which I'll learn later

        int n = s.length();

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int currLen = j - i + 1;

                if (currLen > maxLen && isPalindrome(s, i, j)) {
                    start = i;
                    maxLen = currLen;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// Problem Link : https://leetcode.com/problems/longest-palindromic-substring/
