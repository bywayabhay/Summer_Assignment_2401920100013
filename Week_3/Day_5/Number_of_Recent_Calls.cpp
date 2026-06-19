#include <bits/stdc++.h>
class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        // TC -> O(1) Amortized
        // SC -> O(n)

        q.push(t);

        // remove all requests outside the range [t - 3000, t]
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

// Problem Link : https://leetcode.com/problems/number-of-recent-calls/
