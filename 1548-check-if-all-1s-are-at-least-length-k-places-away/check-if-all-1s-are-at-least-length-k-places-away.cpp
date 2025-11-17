class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastSeenIdx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                lastSeenIdx = i;
                break;
            }
        }

        for (int i = lastSeenIdx + 1; i < nums.size(); i++) {
            if (nums[i] == 1 && (i - lastSeenIdx - 1) < k) {
                return false;
            } else if (nums[i] == 1) {
                lastSeenIdx = i;
            }

            cout << i << ' ' << lastSeenIdx << endl;
        }

        return true;
    }
};