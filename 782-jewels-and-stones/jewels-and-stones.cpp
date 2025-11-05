class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int numJewels = 0;

        unordered_set<char> lookup;

        for (char c : jewels) {
            lookup.insert(c);
        }

        for (char c : stones) {
            if (lookup.find(c) != lookup.end()) {
                numJewels++;
            }
        }

        return numJewels;
    }
};