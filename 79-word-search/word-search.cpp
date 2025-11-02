class Solution {
private:
    int ROWS;
    int COLS;

    bool search(vector<vector<char>>& board, string word, int row, int col, int i) {
        if (i == word.length()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || board[row][col] != word[i]) {
            return false;
        }

        char c = board[row][col];
        board[row][col] = '#';
        bool result = search(board, word, row + 1, col, i + 1)
                        || search(board, word, row, col + 1, i + 1)
                        || search(board, word, row - 1, col, i + 1)
                        || search(board, word, row, col - 1, i + 1);

        board[row][col] = c;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        unordered_map<char, int> boardCount, wordCount;

        for (const auto& row : board) {
            for (char c : row) {
                boardCount[c]++;
            }
        }

        for (char c : word) {
            wordCount[c]++;
            if (wordCount[c] > boardCount[c]) {
                return false;
            }
        }

        if (boardCount[word[0]] > boardCount[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == word[0]) {
                    if (search(board, word, row, col, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};