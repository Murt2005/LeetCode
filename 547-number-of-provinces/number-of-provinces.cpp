class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result++;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor = 0; neighbor < n; neighbor++) {
                        if (isConnected[node][neighbor] && !visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push({neighbor});
                        }
                    }
                }
            }
        }

        return result;
    }
};

/*

[1,1,0,0]
[1,1,0,0]
[0,0,1,1]
[0,0,0,0]


[0:1]

[1:0]

[2:3]




*/