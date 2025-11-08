class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int have = 0;
        int needCount = need.size();
        int start = 0;
        int minLength = INT_MAX;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    have++;
                }
            }

            while (have == needCount) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                
                char lc = s[left];
                if (need.count(lc)) {
                    window[lc]--;
                    if (window[lc] < need[lc]) {
                        have--;
                    }
                }
                left++;
            }
        }
        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }
};