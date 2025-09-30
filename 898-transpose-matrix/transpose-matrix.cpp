class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        vector<vector<int>> result(COLS, vector<int>(ROWS));

        for (int col = 0; col < COLS; col++) {
            for (int row = 0; row < ROWS; row++) {
                result[col][row] = matrix[row][col];
            }
        }
        
        return result;
    }
};