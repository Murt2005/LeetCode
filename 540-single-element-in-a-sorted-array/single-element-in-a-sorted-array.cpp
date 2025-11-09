class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;

        while (leftPtr < rightPtr) {
            int middlePtr = (leftPtr + rightPtr) / 2;
            int nextLeft = middlePtr - 1;
            int nextRight = middlePtr + 1;

            if (nextLeft >= 0 && nums[nextLeft] == nums[middlePtr]) {
                if (nextLeft % 2 == 1) {
                    rightPtr = middlePtr - 1;
                } else {
                    leftPtr = middlePtr + 1;
                }
            } else if (nextRight < nums.size() && nums[nextRight] == nums[middlePtr]) {
                if (middlePtr % 2 == 1) {
                    rightPtr = middlePtr - 1;
                } else {
                    leftPtr = middlePtr + 1;
                }
            } else {
                return nums[middlePtr];
            }
        }

        return nums[rightPtr];
    }
};



/*
   m 
[1,1,2,3,3,4,4,8,8]
 l   r

left = 0;
right = 2
middle = 1



algorithm:
- check the position on the nextLeft from the middle and on the nextRight from the middle
- if nums[nextLeft] == nums[middle] then nextLeft must be the first value of the pair
    - check if nextLeft is odd or even
        - if nextLeft is odd move nextLeft to middle + 1
        - if nextLeft is even move nextRight to middle - 1
- if nums[nextRight] == nums[nextRight] then middle must be the first value of the pair
    - check if middle is odd or even
        - if middle is odd then move right to middle - 1
        - if middle is even then move left to middle + 1
- if middle is not equal to nextRight or nextLeft return nums[middle]


*/