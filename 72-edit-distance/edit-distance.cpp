class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return helper(word1, word2, 0, 0, memo);
    }
private:
    int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i == word1.length()) {
            return word2.length() - j;
        }

        if (j == word2.length()) {
            return word1.length() - i;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (word1[i] == word2[j]) {
            memo[i][j] = helper(word1, word2, i + 1, j + 1, memo);
            return memo[i][j];
        }

        int replace = helper(word1, word2, i + 1, j + 1, memo) + 1;

        int add = helper(word1, word2, i, j + 1, memo) + 1;

        int remove = helper(word1, word2, i + 1, j, memo) + 1;

        memo[i][j] = min(replace, min(add, remove));

        return memo[i][j];
    }
};

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.length();
//         int n = word2.length();

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for (int i = n - 1; i >= 0; i--) {
//             dp[m][i] = dp[m][i + 1] + 1;
//         }

//         for (int i = m - 1; i >= 0; i--) {
//             dp[i][n] = dp[i + 1][n] + 1;
//         }

//         for (int i = m - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= 0; j--) {
//                 if (word1[i] == word2[j]) {
//                     dp[i][j] = dp[i+1][j+1];
//                 } else {
//                     dp[i][j] = min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j + 1])) + 1;
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

/*




*/