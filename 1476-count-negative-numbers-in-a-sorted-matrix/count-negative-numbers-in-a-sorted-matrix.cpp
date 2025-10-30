class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int row = 0;
        int col = COLS - 1;

        while (row < ROWS && col >= 0) {
            if (grid[row][col] < 0) {
                negativeCount += (ROWS - row);
                col--;
            } else {
                row++;
            }
        }

        return negativeCount;
    }
};



// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int negativeCount = 0;
//         int ROWS = grid.size();
//         int COLS = grid[0].size();
        
//         for (int row = 0; row < ROWS; row++) {
//             for (int col = 0; col < COLS; col++) {
//                 if (grid[row][col] < 0) {
//                     negativeCount++;
//                 }
//             }
//         }

//         return negativeCount;
//     }
// };