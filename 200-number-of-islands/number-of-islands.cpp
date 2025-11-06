class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (grid[row][col] == '1') {
                    bfs(grid, row, col);
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

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto cell = q.front();
                q.pop();
                int x = cell.first;
                int y = cell.second;

                for (int d = 0; d < 4; d++) {
                    int newX = x + directions[d][0];
                    int newY = y + directions[d][1];

                    if (newX >= 0 && newY >= 0 && newX < ROWS && newY < COLS && grid[newX][newY] == '1') {
                        q.push({newX, newY});
                        grid[newX][newY] = '0';
                    }
                }
            }
        }
    }
};