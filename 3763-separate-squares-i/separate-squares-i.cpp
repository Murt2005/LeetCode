class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 2e9;
        double high = 0;

        for (const auto& square : squares) {
            double y = square[1];
            double length = square[2];
            totalArea += length * length;
            low = min(low, y);
            high = max(high, y + length);
        }

        double targetArea = totalArea / 2.0;

        for (int i = 0; i < 100; i++) {
            double mid = low + (high - low) / 2.0;
            double currentArea = 0;

            for (const auto& square : squares) {
                double y = square[1];
                double length = square[2];
                double h_below = max(0.0, min(length, mid - y));
                currentArea += h_below * length;
            }

            if (currentArea < targetArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};