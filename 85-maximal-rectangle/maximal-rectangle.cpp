class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));

        for (int col = 0; col < COLS; col++) {
            int height = 0;
            for (int row = 0; row < ROWS; row++) {
                height += matrix[row][col] - '0';
                if (matrix[row][col] == '0') {
                    height = 0;
                }
                dp[row][col] = height;
            }
        }

        int largestArea = 0;
        for (int row = 0; row < ROWS; row++) {
            largestArea = max(largestArea, helper(dp, row));
        }
        return largestArea;
    }

    int helper(vector<vector<int>>& dp, int row) {
        int n = dp[row].size();
        stack<int> stck;
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            while (!stck.empty() && (i == n || dp[row][i] < dp[row][stck.top()])) {
                int height = dp[row][stck.top()];
                stck.pop();
                int width = stck.empty() ? i : i - stck.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            stck.push(i);
        }
        return maxArea;
    }
};