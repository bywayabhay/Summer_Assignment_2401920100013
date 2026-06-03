class Solution {
public:
    int maxArea(vector<int>& height) {
        // TC -> O(n)
        // SC -> O(1)

        int n = height.size();
        int maxArea = 0;

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int currHeight = min(height[i], height[j]);
            int width = j - i;
            int area = currHeight * width;

            maxArea = max(maxArea, area);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxArea;
    }
};

// Problem Link: https://leetcode.com/problems/container-with-most-water/
