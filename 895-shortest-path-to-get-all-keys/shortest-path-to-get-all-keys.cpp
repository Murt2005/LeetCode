class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int startRow = -1;
        int startCol = -1;
        int totalKeys = 0;

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (grid[row][col] == '@') {
                    startRow = row;
                    startCol = col;
                } else if (islower(grid[row][col])) {
                    totalKeys++;
                }
            }
        }
        queue<tuple<int, int, int>> q;
        set<tuple<int, int, int>> visited;
        
        q.push({startRow, startCol, 0});
        visited.insert({startRow, startCol, 0});

        int moves = 0;
        int allKeysMask = (1 << totalKeys) - 1;

        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                auto [row, col, keysMask] = q.front();
                q.pop();

                if (keysMask == allKeysMask) {
                    return moves;
                }
                for (int d = 0; d < 4; d++) {
                    int newRow = row + directions[d][0];
                    int newCol = col + directions[d][1];
                    
                    if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS) {
                        continue;
                    }

                    char cell = grid[newRow][newCol];

                    if (cell == '#') {
                        continue;
                    }

                    int newKeysMask = keysMask;

                    if (islower(cell)) {
                        int keyIndex = cell - 'a';
                        newKeysMask |= (1 << keyIndex);
                    } else if (isupper(cell)) {
                        int keyIndex = cell - 'A';
                        if (!(keysMask & (1 << keyIndex))) {
                            continue;
                        }
                    }
                    tuple<int, int, int> newState = {newRow, newCol, newKeysMask};
                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }
            moves++;
        }
        return -1;
    }

private:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
};