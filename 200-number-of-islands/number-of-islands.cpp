class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    result++;
                }
            }
        }

        return result;    
    }

private:
    int ROWS;
    int COLS;
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        for (int d = 0; d < 4; d++) {
            int newRow = row + directions[d][0];
            int newCol = col + directions[d][1];

            if (newRow >= 0 && newCol >= 0 && newRow < ROWS && newCol < COLS && grid[newRow][newCol] != '0') {
                dfs(grid, newRow, newCol);
            }
        }
    }
};