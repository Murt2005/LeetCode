class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = 0;

        for (int pile : piles) {
            maxSpeed = max(maxSpeed, pile);
        }

        while (minSpeed < maxSpeed) {
            int middleSpeed = (minSpeed + maxSpeed) / 2;

            if (validateSpeed(piles, h, middleSpeed)) {
                maxSpeed = middleSpeed;
            } else {
                minSpeed = middleSpeed + 1;
            }
        }

        return maxSpeed;
    }

private:
    bool validateSpeed(vector<int>& piles, int h, int middleSpeed) {
        int hour = 0;

        for (int pile : piles) {
            hour += (pile % middleSpeed == 0) ? pile / middleSpeed : pile / middleSpeed + 1;
        }

        return hour <= h;
    }
};

/*







*/