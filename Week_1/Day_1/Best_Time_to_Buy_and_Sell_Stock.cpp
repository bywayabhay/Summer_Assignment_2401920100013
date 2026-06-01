class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TC -> O(n)
        // SC -> O(1)
        int n = prices.size();
        int buyPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            } else {
                int currProfit = prices[i] - buyPrice;
                profit = max(currProfit, profit);
            }
        }
        return profit;
    }
};

// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
