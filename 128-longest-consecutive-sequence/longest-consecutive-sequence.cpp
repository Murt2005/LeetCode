class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> encountered;

        for (int num : nums) {
            encountered.insert(num);
        }

        int longestSequence = 0;
        for (int num : encountered) {
            if (encountered.find(num - 1) != encountered.end()) {
                continue;
            } else {
                int currentSequence = 1;
                while (encountered.find(num + currentSequence) != encountered.end()) {
                    currentSequence++;
                }
                longestSequence = max(longestSequence, currentSequence);
            }
        }

        return longestSequence;
    }
};

/*

given: unsorted arr of ints

return: length of longest consecutive elements

ds:
- unordered_set<int> vals encountered

algorithm:
- iterate through input arr and store vals in the encountered set
- iterate through the encountered set, to prevent checking duplicate vals
  - check is this the start of a sequence? check by checking if nums[i] - 1 is in the set
  - if it is not the start of a sequence, skip it
  - if it is, keep track of how long that sequence goes for
  - return the max sequence found



*/