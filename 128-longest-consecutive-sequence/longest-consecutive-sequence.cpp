class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;

        for (int num : nums) {
            lookup.insert(num);
        }

        int maxStreak = 0;
        for (int num : lookup) {
            if (lookup.find(num - 1) != lookup.end()) {
                continue;
            }

            int streak = 1;
            while (lookup.find(num + streak) != lookup.end()) {
                streak++;
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak;
    }
};

/*
O(NlogN)

[1,2,3,4,100,200]
 


O(N)

[100,4,200,1,3,2]

put all elements in an unordered_set<>




*/