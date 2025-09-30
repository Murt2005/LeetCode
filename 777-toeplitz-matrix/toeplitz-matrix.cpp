class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        for (int row = 1; row < ROWS; row++) {
            for (int col = 1; col < COLS; col++) {
                if (matrix[row][col] != matrix[row-1][col-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};