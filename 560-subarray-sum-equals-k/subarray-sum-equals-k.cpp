class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSubarrays = 0;
        unordered_map<int, int> lookup; // sum of subarray -> number of subarrays with that sum
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


/*

given: arr of ints and value k

return: number of total subarrays who sum equals to k


1 <= nums.length() <= 2 * 10^4

-1000 <= nums[i] <= 1000

return 0 if no subarrays found




[1,1,1] k = 2

[1,1]

[1,1]

return 2


[1,2,3]


unorderded_map<int, int> with key: sum of subarray ending at index i, value: i

totalSum = 3

[1,1,1]
     ^

[[0,0], [1:0], [2:1], [3:2]]


k = totalSum - targetvalue
targetValue = totalSum - k


if (map.find(targetValue))
    map[targetValue] = start index of that subarray


result = 1



[1,1,-1,2,-2]  k = 0
           ^

totalSum = 1;

targetValue = totalSum - k

check that targetValue exists before putting into map

[[0,1], [1:2], ]

result = 3;

*/