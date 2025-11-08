class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int smallestSum = 0;
        int maxSum = 0;

        for (int num : nums) {
            smallestSum = max(smallestSum, num);
            maxSum += num;
        }

        while (smallestSum < maxSum) {
            int middleSum = (smallestSum + maxSum) / 2;

            if (validate(nums, k, middleSum)) {
                maxSum = middleSum;
            } else {
                smallestSum = middleSum + 1;
            }
        }

        return maxSum;
    }

private:
    bool validate(vector<int>& nums, int k, int middleSum) {
        int subarrays = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= middleSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
            }
        }

        return subarrays <= k;
    }
};



/*

given: arr of ints, int k

need to: split the subbarray

return: minimized largest sum of the split



*/