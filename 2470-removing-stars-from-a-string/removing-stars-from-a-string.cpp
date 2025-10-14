class Solution {
public:
    string removeStars(string s) {
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < s.length(); readIndex++) {
            if (s[readIndex] == '*') {
                if (writeIndex > 0) {
                    writeIndex--;
                }
            } else {
                s[writeIndex] = s[readIndex];
                writeIndex++;
            }
        }
        return s.substr(0, writeIndex);
    }
};