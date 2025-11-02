class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        for (int num : nums) {
            freqCount[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [num, freq] : freqCount) {
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};