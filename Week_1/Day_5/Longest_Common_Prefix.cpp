class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // TC -> O(n log n * m)
        // SC -> O(1) (excluding output string)
        // n-> no. of strings in vector
        // m-> max length of a string

        int n = strs.size();

        // Sort strings in lexicographical order
        sort(strs.begin(), strs.end());

        string lcp = "";

        // Take the first and last strings after sorting
        string first = strs[0];
        string last = strs[n - 1];

        // Find common characters between first and last string
        for (int i = 0; i < first.length(); i++) {
            if (first[i] != last[i])
                break;

            lcp.push_back(first[i]);
        }

        return lcp;
    }
};

// Problem Link: https://leetcode.com/problems/longest-common-prefix/
