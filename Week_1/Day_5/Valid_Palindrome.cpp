class Solution {
private:
    bool isAlNum(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9'));
    }

public:
    bool isPalindrome(string s) {
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            while (left < right && !isAlNum(s[left]))
                left++;

            while (left < right && !isAlNum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

// Problem Link: https://leetcode.com/problems/valid-palindrome/
