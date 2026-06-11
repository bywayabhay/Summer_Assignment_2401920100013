class Solution {
private:
    void generateParenthesisHelper(int open, int close, string s,
                                   vector<string>& ans, int n) {
        // this path will never give me valid parenthesis
        if (open > n)
            return;

        // reach the end as We have to fil  2 * n places
        // so if open != close -> Not a valid parenthesis
        if (open == close && (open + close) == 2 * n) {
            ans.push_back(s);
            return;
        }

        // adding open bracket as starting with closing bracket will never lead
        // to balanced parenthethis
        generateParenthesisHelper(open + 1, close, s + '(', ans, n);

        // check if (possibilities left)
        if (open > close)
            generateParenthesisHelper(open, close + 1, s + ')', ans, n);
    }

public:
    vector<string> generateParenthesis(int n) {
        // TC -> O(4^n / sqrt(n))
        // SC -> O(n)

        vector<string> ans;
        generateParenthesisHelper(0, 0, "", ans, n);
        return ans;
    }
};

// Problem Link : https://leetcode.com/problems/generate-parentheses/
