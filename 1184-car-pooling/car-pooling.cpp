class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> delta(1001, 0);

        for (auto& trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            delta[from] += passengers;
            delta[to] -= passengers;
        }

        int currentPassangers = 0;
        for (int i = 0; i <= 1000; i++) {
            currentPassangers += delta[i];
            if (currentPassangers > capacity) {
                return false;
            }
        }

        return true;
    }
};