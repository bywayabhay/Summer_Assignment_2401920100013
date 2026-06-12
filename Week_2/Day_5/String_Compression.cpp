class Solution {
public:
    int compress(vector<char>& chars) {
        // TC -> O(n)
        // SC -> O(1)

        int n = chars.size();

        int i = 1;
        int cnt = 1;
        int j = 0;

        while (i < n) {
            if (chars[i] == chars[i - 1])
                cnt++;
            else {
                chars[j++] = chars[i - 1];

                if (cnt > 1) {
                    string freq = to_string(cnt);
                    for (auto ch : freq)
                        chars[j++] = ch;
                }

                cnt = 1;
            }

            i++;
        }

        chars[j++] = chars[i - 1];

        if (cnt > 1) {
            string freq = to_string(cnt);
            for (auto ch : freq)
                chars[j++] = ch;
        }

        return j;
    }
};

// Problem Link : https://leetcode.com/problems/string-compression/
