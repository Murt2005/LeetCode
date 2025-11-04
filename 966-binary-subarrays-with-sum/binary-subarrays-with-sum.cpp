class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }

private:
    int helper(vector<int>& nums, int goal) {
        int start = 0;
        int currentSum = 0;
        int result = 0;

        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];

            while (start <= end && currentSum > goal) {
                currentSum -= nums[start];
                start++;
            }

            result += end - start + 1;
        }

        return result;
    }
};



// Time Complexity: O(N)
// Space Complexity: O(N)
//
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int totalSum = 0;
//         int result = 0;

//         unordered_map<int, int> freq;

//         for (int num : nums) {
//             totalSum += num;
            
//             if (totalSum == goal) {
//                 result++;
//             }

//             if (freq.find(totalSum - goal) != freq.end()) {
//                 result += freq[totalSum - goal];
//             }

//             freq[totalSum]++;
//         }

//         return result;
//     }
// };