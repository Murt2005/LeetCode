class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        int n = piles.size();
        int left = 1;
        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);   
        }

        while (left <= right) {
            int speed = left + (right - left) / 2;
            int totalHours = 0;
            for (int i = 0; i < n; i++) {
                totalHours += (piles[i] % speed == 0) ? piles[i] / speed : piles[i] / speed + 1;

                if (totalHours > h) {
                    break;
                }
            }
            if (totalHours <= h) {
                right = speed - 1;
            } else {
                left = speed + 1;
            }
        }
        return left;
    }
};


/*

[3,6,7,11]

min: 3
max: 11

7


*/