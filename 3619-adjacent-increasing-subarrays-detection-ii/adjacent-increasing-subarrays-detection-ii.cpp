class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> increaseCount(n, 0);

        increaseCount[0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                increaseCount[i] = 1 + increaseCount[i - 1];
            } else {
                increaseCount[i] = 1;
            }
        }

        int k = 0;

        for (int i = 0; i < n; i++) {
            int len = increaseCount[i];

            if (i >= len) {
                int prevlen = increaseCount[i - len];
                if (prevlen >= len) {
                    k = max(k, len);
                }
            }

            k = max(k, len / 2);
        }

        return k;
    }
};

/*

nums = [2,5,7,8,9,2,3,4,3,1]

increaseCount = [1,2,3,4,5,1,2,3,1,1]


*/