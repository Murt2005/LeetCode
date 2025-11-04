class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

/*

[3,4,-1,1]
[3,4,5,-1]

*/

// Time Complexity: O(NlogN)
// Space Complexity: O(1)
//
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int target = 1;
//         for (int num : nums) {
//             if (num > 0 && num == target) {
//                 target++;
//             } else if (num > target) {
//                 return target;
//             }
//         }

//         return target;
//     }
// };

/*

[1,2,0]

[3,4,-1,1]

[-1,1,3,4]


*/