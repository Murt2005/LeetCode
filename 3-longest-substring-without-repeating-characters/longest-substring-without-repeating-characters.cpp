class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leftPtr = 0;
        int rightPtr = 0;
        unordered_map<char, int> lookup; // char -> last seen index

        int longestSubstring = 0;

        while (rightPtr < s.length()) {
            if (lookup.find(s[rightPtr]) != lookup.end()) {
                int lastSeenIdx = lookup[s[rightPtr]];

                while (leftPtr <= lastSeenIdx) {
                    lookup.erase(s[leftPtr]);
                    leftPtr++;
                }
            }

            lookup[s[rightPtr]] = rightPtr;
            longestSubstring = max(longestSubstring, rightPtr - leftPtr + 1);
            rightPtr++;
        }

        return longestSubstring;        
    }
};



/*

[[p:1], [w:2]]

"pwwkew"
 ^
   ^

algorithm:
- use a unordered_map<char, int> lookup that maps char -> last seen index
- use a sliding window
- expand sliding window when window is valid
    - lookup.find(s[right]) == lookup.end()
- shrink sliding window when window is invalid
    - lookup.find(s[right]) != lookup.end();
    - want to keep shrinking the window until one after the last index at which we saw that char
- for each window keep track of the window size
- return the largest window
*/