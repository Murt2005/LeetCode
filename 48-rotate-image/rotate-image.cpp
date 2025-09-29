class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};

/*

[1,2,3]
[4,5,6]
[7,8,9]


(flip across top left to bottom right diagonal)
[1,4,7]
[2,5,8]
[3,6,9]

(reflect matrix across vertical axis)
[7,4,1]
[8,5,2]
[9,6,3]

*/