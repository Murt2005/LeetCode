class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> aboveRow(n, 1);

        for (int row = 1; row < m; row++) {
            vector<int> currentRow(n , 1);
            for (int col = 1; col < n; col++) {
                currentRow[col] = currentRow[col - 1] + aboveRow[col];
            }
            aboveRow = currentRow;
        }

        return aboveRow[n - 1];
    }
};


/*

[1,1,1,1,1,1,1]
[1,2,3,4,5,6,7]
[1,3,6,10,15,21,28]

*/