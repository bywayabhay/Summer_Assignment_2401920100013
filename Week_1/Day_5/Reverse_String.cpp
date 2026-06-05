class Solution {
public:
    void reverseString(vector<char>& s) {
        // TC -> O(n)
        // SC -> O(1)

        int n = s.size();

        int low = 0;
        int high = n - 1;

        while (low < high) {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};

// Problem Link: https://leetcode.com/problems/reverse-string/
