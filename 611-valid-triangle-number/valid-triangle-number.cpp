class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j];
                    if (sum > nums[k]) {
                        count++;
                    } else {
                        break;
                    }
                }
            }
        }
        return count;
    }
};

/*

[2,2,3,4]

2,3,4
2,2,3


2,3,4,4
i j k


2,3,4
2,3,4
2,4,4
2,4,4

*/