class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int step1 = 1;
        int step2 = 2;

        for (int step = n - 3; step >= 0; step--) {
            int currentStep = step1 + step2;
            step1 = step2;
            step2 = currentStep;
        }

        return step2;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
//
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) {
//             return n;
//         }

//         vector<int> steps(n + 1);
//         steps[n - 1] = 1;
//         steps[n - 2] = 2;

//         for (int step = n - 3; step >= 0; step--) {
//             steps[step] = steps[step + 1] + steps[step + 2];
//         }

//         return steps[0];
//     }
// };