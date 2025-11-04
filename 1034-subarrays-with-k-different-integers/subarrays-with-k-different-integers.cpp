class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMostK(nums, k) - AtMostK(nums, k - 1);
    }

private:
    int AtMostK(vector<int>& nums, int k) {
        int leftPtr = 0;
        int result = 0;
        unordered_map<int, int> numFreq; // num -> freq
        for (int rightPtr = 0; rightPtr < nums.size(); rightPtr++) {
            if (numFreq[nums[rightPtr]] == 0) {
                k--;
            }
            numFreq[nums[rightPtr]]++;


            while (k < 0) {
                numFreq[nums[leftPtr]]--;
                if (numFreq[nums[leftPtr]] == 0) {
                    k++;
                }

                leftPtr++;
            }

            result += rightPtr - leftPtr + 1;
        }

        return result;
    }
};


// Time Complexity: O(N^2)
// Space Complexity: O(N)
//
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int goodArrays = 0;

//         unordered_set<int> contains;

//         for (int i = 0; i < nums.size(); i++) {
//             contains.insert(nums[i]);
//             for (int j = i; j < nums.size(); j++) {
//                 contains.insert(nums[j]);
//                 if (contains.size() == k) {
//                     goodArrays++;
//                 } else if (contains.size() > k) {
//                     break;
//                 }
//             }
//             contains.clear();
//         }

//         return goodArrays;
//     }
// };
/*
generate every possibil subarray
for each subarray, check elements within them
if that subarray is a good subarray, incremenet the result
*/