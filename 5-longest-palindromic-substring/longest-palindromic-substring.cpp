class Solution {
public:
    string longestPalindrome(string s) {
        int resultMax = 0;
        int resultIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resultMax) {
                    resultMax = right - left + 1;
                    resultIndex = left;
                }
                
                left--;
                right++;
            }

            left = i;
            right = i + 1;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resultMax) {
                    resultMax = right - left + 1;
                    resultIndex = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(resultIndex, resultMax);
    }
};

/*


babaad


*/