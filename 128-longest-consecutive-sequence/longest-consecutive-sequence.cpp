class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        for (int num : nums) {
            lookup.insert(num);
        }

        int maxStreak = 0;
        for (int num : lookup) {
            if (!(lookup.contains(num - 1))) {
                int streak = 1;
                while (lookup.contains(num + streak)) {
                    streak++;
                }
                maxStreak = max(streak, maxStreak);
            }
        }
        return maxStreak;
    }
};

/*

[100,4,200,1,3,2]

[100]

*/