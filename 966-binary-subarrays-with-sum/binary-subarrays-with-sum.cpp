class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalSum = 0;
        int result = 0;

        unordered_map<int, int> freq;

        for (int num : nums) {
            totalSum += num;
            
            if (totalSum == goal) {
                result++;
            }

            if (freq.find(totalSum - goal) != freq.end()) {
                result += freq[totalSum - goal];
            }

            freq[totalSum]++;
        }

        return result;
    }
};