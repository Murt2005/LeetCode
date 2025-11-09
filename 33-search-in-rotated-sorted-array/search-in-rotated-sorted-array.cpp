class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] == target) {
                return middle;
            }

            if (nums[left] <= nums[middle]) {
                if (nums[left] <= target && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                if (nums[right] >= target && target > nums[middle]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return -1;
    }
};