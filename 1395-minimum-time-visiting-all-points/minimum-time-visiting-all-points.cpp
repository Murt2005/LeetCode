class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int seconds = 0;

        for (int i = 0; i < n - 1; i++) {
            auto currentPointCords = points[i];
            int currentX = currentPointCords[0];
            int currentY = currentPointCords[1];

            auto nextPointCords = points[i + 1];
            int nextX = nextPointCords[0];
            int nextY = nextPointCords[1];

            int xDistance = currentX - nextX;
            int yDistance = currentY - nextY;

            int dx = abs(nextX - currentX);
            int dy = abs(nextY - currentY);

            seconds += max(dx, dy);
        }

        return seconds;
    }
};