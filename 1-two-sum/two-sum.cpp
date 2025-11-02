class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (numToIndex.find(target - nums[i]) != numToIndex.end()) {
                return {i, numToIndex[target - nums[i]]};
            }
            numToIndex[nums[i]] = i;
        }

        return {};
    }
};


// BRUTE FORCE SOLUTION
// TIME COMPLEXITY: O(N^2)
// SPACE COMPLEXITY: O(1)
//
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size() - 1; i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };