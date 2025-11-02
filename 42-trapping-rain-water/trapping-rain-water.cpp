class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        int maxL = 0;
        for (int i = 1; i < n; i++) {
            maxL = max(maxL, height[i - 1]);
            maxLeft[i] = maxL;
        }

        int maxR = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxR = max(maxR, height[i + 1]);
            maxRight[i] = maxR;
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int water = min(maxLeft[i], maxRight[i]) - height[i];
            if (water > 0) {
                totalWater += water;
            }
        }

        return totalWater;
    }
};


/*

height = [0,1,0,2,1,0,1,3,2,1,2,1]

maxlef = [0,0,1,1,2,2,2,2,3,3,3,3]
maxrig = [3,3,3,3,3,3,3,2,2,2,1,0]
minlr  = [0,0,1,1,2,2,2,2,2,2,1,0]
*/