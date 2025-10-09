class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, visited, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }

private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room) {
        if (visited[room] == true) {
            return;
        }

        visited[room] = true;
        for (int r = 0; r < rooms[room].size(); r++) {
            dfs(rooms, visited, rooms[room][r]);
        }
    }
};