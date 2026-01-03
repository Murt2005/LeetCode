class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long aba = 6;
        long long abc = 6;

        for (int i = 2; i <= n; i++) {
            long long new_aba = (aba * 3 + abc * 2) % MOD;
            long long new_abc = (aba * 2 + abc * 2) % MOD;

            aba = new_aba;
            abc = new_abc;
        }

        return (aba + abc) % MOD;
    }
};




// TLEs 
//
//
// class Solution {
// public:
//     int MOD = 1e9 + 7;


//     int numOfWays(int n) {
//         vector<vector<int>> grid(n, vector<int>(3, 0));
//         unordered_map<string, int> memo;
//         return dfs(grid, 0, 0, memo);
//     }

// private:
//     int dfs(vector<vector<int>>& grid, int row, int col, unordered_map<string, int>& memo) {
//         int n = grid.size();

//         if (row == n) {
//             return 1;
//         }

//         if (col == 3) {
//             return dfs(grid, row + 1, 0, memo);
//         }

//         string state = gridToState(grid, row, col);

//         if (memo.find(state) != memo.end()) {
//             return memo[state];
//         }

//         int ways = 0;

//         for (int color = 1; color <= 3; color++) {
//             if (isValid(grid, row, col, color)) {
//                 grid[row][col] = color;
//                 ways = (ways + dfs(grid, row, col + 1, memo)) % MOD;
//                 grid[row][col] = 0;
//             }
//         }

//         memo[state] = ways;
//         return ways;
//     }

//     bool isValid(vector<vector<int>>& grid, int row, int col, int color) {
//         if (col > 0 && grid[row][col - 1] == color) {
//             return false;
//         }

//         if (row > 0 && grid[row - 1][col] == color) {
//             return false;
//         }

//         return true;
//     }

//     string gridToState(vector<vector<int>>& grid, int row, int col) {
//         string s = to_string(row) + "," + to_string(col) + ":";

//         if (row > 0) {
//             for (int j = 0; j < 3; j++) {
//                 s += to_string(grid[row - 1][j]);
//             }
//         }

//         s += "|";

//         for (int j = 0; j < col; j++) {
//             s += to_string(grid[row][j]);
//         }

//         return s;
//     }
// };

/*

Use backtracking

paint the grid by going from left to right and top to bottom using dfs + backtracking

can speed this up by then using memoization and storing the states so I don't have repeated work

to store states I can use
- vector<vector<int>> grid(n, vector<int>(3, 0))
- 0 represents unfilled, 1 is red, 2 is yellow, 3 is green

have a helper function that will get repeatedly called to paint the grid
- keep track of what cell I am painting in the grid
- look in each direction (left, right, up, down) and for each direction and figure out what color(s) I can paint the cell
- paint the cell for each possible color and call the function again with the updated cell, cell to the right or cell to next row on the very left


*/