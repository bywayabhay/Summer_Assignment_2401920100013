class Solution {
private:
    string generate(string word) {
        vector<int> freq(27, 0);

        for (int i = 0; i < word.length(); i++)
            freq[word[i] - 'a']++;

        string newWord = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                newWord += string(freq[i], i + 'a');
        }

        return newWord;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TC -> O(n * k)
        // SC -> O(n * k)

        int n = strs.size();

        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            string word = strs[i];

            string newWord = generate(word);

            mpp[newWord].push_back(word);
        }

        for (auto& it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Problem Link : https://leetcode.com/problems/group-anagrams/
