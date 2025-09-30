class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordFreq;
        for (auto& word : words) {
            wordFreq[word]++;
        }

        int longestLength = 0;
        bool hasMiddle = false;

        for (auto& [word, count] : wordFreq) {
            string reverse = string{word[1], word[0]};
            if (word == reverse) {
                longestLength += (count / 2) * 4;
                if (count % 2 == 1) hasMiddle = true;
            } else if (wordFreq.contains(reverse)) {
                int pairs = min(count, wordFreq[reverse]);
                longestLength += pairs * 4;
                wordFreq[word] = 0;
            }
        }
        if (hasMiddle) longestLength += 2;
        return longestLength;
    }
};