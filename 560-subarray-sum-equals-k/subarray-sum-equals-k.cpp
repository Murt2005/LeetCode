class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSubarrays = 0;
        unordered_map<int, int> lookup;
        lookup[0] = 1;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            int targetValue = sum - k;
            if (lookup.find(targetValue) != lookup.end()) {
                totalSubarrays += lookup[targetValue];
            }
            lookup[sum]++;
        }
        return totalSubarrays;
    }
};