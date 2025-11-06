class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int minSteps = 0;

        if (ROWS == 1 && COLS == 1) {
            return 0;
        }

        vector<vector<vector<bool>>> visited(ROWS, vector<vector<bool>>(COLS, vector<bool>(k +1, false)));

        visited[0][0][k] = true;

        queue<pair<int, pair<int,int>>> q; // {k, row, col}
        q.push({k, {0, 0}});

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto cell = q.front();
                q.pop();
                int kLeft = cell.first;
                int x = cell.second.first;
                int y = cell.second.second;

                for (int d = 0; d < 4; d++) {
                    int newX = x + directions[d][0];
                    int newY = y + directions[d][1];
                    int newKLeft = kLeft;

                    if (newX < 0 || newY < 0 || newX >= ROWS || newY >= COLS) {
                        continue;
                    }

                    if (grid[newX][newY] == 1) {
                        newKLeft--;
                    }

                    if (newKLeft < 0) {
                        continue;
                    }

                    if (visited[newX][newY][newKLeft]) {
                        continue;
                    }

                    if (newX == ROWS - 1 && newY == COLS - 1) {
                        return minSteps + 1;
                    }

                    q.push({newKLeft, {newX, newY}});
                    visited[newX][newY][newKLeft] = true;
                }
            }
            minSteps++;
        }


        return -1;
    }

private:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
};