class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if (grid[0][0] == 1) {
            return -1;
        }

        if (ROWS == 1 && COLS == 1 && grid[0][0] == 0) {
            return 1;
        }

        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0,0});
        int shortestPath = 0;

        while (!q.empty()) {
            int qSize = q.size();
            for (int s = 0; s < qSize; s++) {
                auto cell = q.front();
                q.pop();
                int x = cell.first;
                int y = cell.second;

                if (x == ROWS - 1 && y == COLS - 1) {
                    return shortestPath + 1;
                }

                for (int d = 0; d < 8; d++) {
                    int newX = x + directions[d][0];
                    int newY = y + directions[d][1];

                    if (newX >= 0 && newY >= 0 && newX < ROWS && newY < COLS && grid[newX][newY] == 0) {
                        q.push({newX, newY});
                        grid[newX][newY] = 1;
                    }
                }
            }
            shortestPath++;
        }

        return -1;
    }

private:
    int directions[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
};