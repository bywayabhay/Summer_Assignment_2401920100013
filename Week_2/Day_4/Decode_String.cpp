class Solution {
public:
    string decodeString(string s) {
        // TC -> O(n * k)
        // SC -> O(n)

        stack<int> numSt;
        stack<string> strSt;

        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                numSt.push(num);
                strSt.push(currStr);

                num = 0;
                currStr = "";
            } else if (ch == ']') {
                int cnt = numSt.top();
                numSt.pop();

                string prevStr = strSt.top();
                strSt.pop();

                string temp = "";

                while (cnt--) {
                    temp += currStr;
                }

                currStr = prevStr + temp;
            } else {
                currStr += ch;
            }
        }

        return currStr;
    }
};

// Problem Link : https://leetcode.com/problems/decode-string/
