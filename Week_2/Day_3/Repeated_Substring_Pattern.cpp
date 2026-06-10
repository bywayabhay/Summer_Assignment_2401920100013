class Solution {
private:
    void findLPS(string s, vector<int>& LPS, int n) {
        int length = 0;
        LPS[0] = 0;
        int i = 1;

        while (i < n) {
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
    bool repeatedSubstringPattern(string s) {
        // TC -> O(n)
        // SC -> O(n)
        int n = s.length();

        vector<int> LPS(n, 0);
        findLPS(s, LPS, n);

        int len = LPS[n - 1];

        return (len > 0 && n % (n - len) == 0);
    }
};

// Problem Link : https://leetcode.com/problems/repeated-substring-pattern/
