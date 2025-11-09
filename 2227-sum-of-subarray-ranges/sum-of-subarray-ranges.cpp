class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long totalSum = 0;
        int minVal = 0;
        int maxVal = 0;

        for (int i = 0; i < nums.size(); i++) {
            minVal = nums[i];
            maxVal = nums[i];
            for (int j = i; j < nums.size(); j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                totalSum += maxVal - minVal;
            }
        }
        return totalSum;
    }

};

/*

nums = [1,2,3]

- use two for loops to iterate through teh array.
- keep track of the min and the max for each loop
- when adding a new element to the subarray in teh second for loop, check for if the new val is a max or min, update accordingly
- when resetting and starting a new subarray, reset the max and the min to the first value.
- after each inner second for loop subtract the max from the min and add it the sum



*/