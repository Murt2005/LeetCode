class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        for (int i = 0, x = 0, y = 0, d = 1; i < m * n; i++) {
            result.push_back(mat[x][y]);

            x -= d;
            y += d;

            if (y >= n) {
                x += 2;
                y = n - 1;
                d = -d;
            }
            if (x >= m) {
                y += 2;
                x = m - 1;
                d = -d;
            }
            if (x < 0) {
                x = 0;
                d = -d;
            }
            if (y < 0) {
                y = 0;
                d = -d;
            }
        }
        return result;
    }
};