class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] %= 2;
        }

        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;

        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;

            if (prefixSumFreq.contains(currentSum - k)) {
                count += prefixSumFreq[currentSum - k];
            }

            prefixSumFreq[currentSum]++;
        }
        
        return count;
    }
};

/*

[1,1,0,1,1] k=3
[1,2,2,3,4]
*/