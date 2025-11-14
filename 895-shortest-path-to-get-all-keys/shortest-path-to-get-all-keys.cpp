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
        queue<tuple<int, int, string>> q;
        set<tuple<int, int, string>> visited;
        
        q.push({startRow, startCol, ""});
        visited.insert({startRow, startCol, ""});

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                auto [row, col, keys] = q.front();
                q.pop();

                if (keys.length() == totalKeys) {
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

                    string newKeys = keys;

                    if (islower(cell)) {
                        if (keys.find(cell) == string::npos) {
                            newKeys += cell;
                            sort(newKeys.begin(), newKeys.end());
                        }
                    } else if (isupper(cell)) {
                        char neededKey = tolower(cell);
                        if (keys.find(neededKey) == string::npos) {
                            continue;
                        }
                    }
                    tuple<int, int, string> newState = {newRow, newCol, newKeys};
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