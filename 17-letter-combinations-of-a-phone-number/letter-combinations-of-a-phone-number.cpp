class Solution {
public:
    vector<string> letterCombinations(string digits) {
        backtrack(digits, 0, "");

        return result;

    }

private:
    vector<string> result;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int i, string curr) {
        if (i >= digits.length()) {
            result.push_back(curr);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            curr.push_back(c);
            backtrack(digits, i + 1, curr);
            curr.pop_back();
        }
    }
};