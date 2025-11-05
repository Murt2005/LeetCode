class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        auto cmp = [](auto& a, auto& b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        visited[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int time = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            if (x == ROWS - 1 && y == COLS - 1) {
                return time;
            }

            for (int d = 0; d < 4; d++) {
                int newX = x + directions[d][0];
                int newY = y + directions[d][1];

                if (newX >= 0 && newY >= 0 && newX < ROWS && newY < COLS && !visited[newX][newY]) {
                    int newTime = max(time, grid[newX][newY]);

                    pq.push({newTime, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }
        return -1;
    }

private:
    int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
};