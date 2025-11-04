class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int readPtr = 0;
        int writePtr = 0;

        while (readPtr < nums.size()) {
            if (nums[readPtr] != val) {
                nums[writePtr] = nums[readPtr];
                writePtr++;
            }

            readPtr++;
        }

        return writePtr;
    }
};

/*





*/