class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, n, 0);
        return result;
    }

private:
    vector<vector<string>> result;
    unordered_set<int> colVisited;
    unordered_set<int> posDiagVisited;
    unordered_set<int> negDiagVisited;

    void backtrack(vector<string>& board, int n, int r) {
        if (r >= n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (colVisited.count(c) || posDiagVisited.count(r + c) || negDiagVisited.count(r - c)) {
                continue;
            }

            colVisited.insert(c);
            posDiagVisited.insert(r + c);
            negDiagVisited.insert(r - c);
            board[r][c] = 'Q';

            backtrack(board, n, r + 1);

            board[r][c] = '.';
            colVisited.erase(c);
            posDiagVisited.erase(r + c);
            negDiagVisited.erase(r - c);
        }
    }
};