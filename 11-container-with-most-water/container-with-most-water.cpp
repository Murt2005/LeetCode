class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        
        int leftPtr = 0;
        int rightPtr = height.size() - 1;

        while (leftPtr < rightPtr) {
            int leftH = height[leftPtr];
            int rightH = height[rightPtr];

            int area = min(leftH, rightH) * (rightPtr - leftPtr);
            result = max(result, area);

            if (leftH <= rightH) {
                leftPtr++;
            } else {
                rightPtr--;
            }
        }

        return result;
    }
};