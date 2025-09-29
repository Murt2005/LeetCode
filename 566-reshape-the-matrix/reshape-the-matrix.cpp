class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r, vector<int>(c));
        int ROWS = mat.size();
        int COLS = mat[0].size();
        if (r * c != ROWS * COLS) {
            return mat;
        }

        int x = 0;
        int y = 0;
        for (int ROW = 0; ROW < ROWS; ROW++) {
            for (int COL = 0; COL < COLS; COL++) {
                result[x][y] = mat[ROW][COL];
                y++;
                if (y == c) {
                    y = 0;
                    x++;
                }
            }
        }
        return result;
    }
};