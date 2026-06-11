class Solution {
public:
    string reverseWords(string s) {
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int start = 0;

        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};

// Problem Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/
