class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int row = ROWS - 1; row >= 0; row--) {
            for (int col = COLS - 1; col >= 0; col--) {
                if (matrix[row][col] == 1) {
                    dp[row][col] = 1 + min(dp[row+1][col], min(dp[row+1][col+1], dp[row][col+1]));
                }
                result += dp[row][col];
            }
        }

        return result;
    }
};