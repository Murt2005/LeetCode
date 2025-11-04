class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numCount;

        for (int num : nums) {
            numCount[num]++;
        }

        int result = 0;
        int resultFreq = 0;
        for (const auto& [num, count] : numCount) {
            if (count > resultFreq) {
                resultFreq = count;
                result = num;
            }
        }

        return result;
    }
};