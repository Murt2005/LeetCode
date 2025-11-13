class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int totalOranges = 0;
        int rottenOranges = 0;

        queue<pair<int, int>> q;

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                    rottenOranges++;
                    totalOranges++;
                }

                if (grid[row][col] == 1) {
                    totalOranges++;
                }
            }
        }

        int minMinutes = 0;

        while (!q.empty()) {
            int qSize = q.size();
            for (int s = 0; s < qSize; s++) {
                auto cell = q.front();
                q.pop();

                int x = cell.first;
                int y = cell.second;

                for (int d = 0; d < 4; d++) {
                    int newX = x + directions[d][0];
                    int newY = y + directions[d][1];

                    if (newX >= 0 && newY >= 0 && newX < ROWS && newY < COLS && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        rottenOranges++;
                        q.push({newX, newY});
                    }
                }
            }
            if (!q.empty()) {
                minMinutes++;
            }
        }

        return (rottenOranges == totalOranges) ? minMinutes : -1;
    }

private:
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
};