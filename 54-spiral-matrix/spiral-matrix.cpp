class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int up = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        vector<int> result;

        while (result.size() != m * n) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[up][i]);
            }

            for (int i = up + 1; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }

            if (up != bottom) {
                for (int i = right - 1; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
            }

            if (left != right) {
                for (int i = bottom - 1; i > up; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            up++;
            bottom--;
            left++;
            right--;
        }
        return result;
    }
};