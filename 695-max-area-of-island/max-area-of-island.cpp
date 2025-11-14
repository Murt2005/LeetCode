class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int maxIslandSize = 0;

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (grid[row][col] == 1) {
                    int currentIslandSize = 0;
                    grid[row][col] = -1;
                    dfs(grid, row, col, currentIslandSize);
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }

private:
    int ROWS;
    int COLS;
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

    void dfs(vector<vector<int>>& grid, int row, int col, int& currentIslandSize) {
        currentIslandSize++;
        grid[row][col] = -1;

        for (int d = 0; d < 4; d++) {
            int newRow = row + directions[d][0];
            int newCol = col + directions[d][1];

            if (newRow >= 0 && newCol >= 0 && newRow < ROWS && newCol < COLS && grid[newRow][newCol] == 1) {
                dfs(grid, newRow, newCol, currentIslandSize);
            }
        }
    }
};

/*

[0,0,1,0,0,0,0,1,0,0,0,0,0]
[0,0,0,0,0,0,0,1,1,1,0,0,0]
[0,1,1,0,1,0,0,0,0,0,0,0,0]
[0,1,0,0,1,1,0,0,1,0,1,0,0]
[0,1,0,0,1,1,0,0,1,1,1,0,0]
[0,0,0,0,0,0,0,0,0,0,1,0,0]
[0,0,0,0,0,0,0,1,1,1,0,0,0]
[0,0,0,0,0,0,0,1,1,0,0,0,0]


*/