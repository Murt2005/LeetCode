class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
//
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> numCount;

//         for (int num : nums) {
//             numCount[num]++;
//         }

//         int result = 0;
//         int resultFreq = 0;
//         for (const auto& [num, count] : numCount) {
//             if (count > resultFreq) {
//                 resultFreq = count;
//                 result = num;
//             }
//         }

//         return result;
//     }
// };