class Solution {
public:
    vector<string> letterCombinations(string digits) {
        backtrack(digits, "", 0);
        return result;
    }

private:
    vector<string> result;
    vector<string> digitsToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, string curr, int i) {
        if (i >= digits.length()) {
            result.push_back(curr);
            return;
        }

        string chars = digitsToChar[digits[i] - '0'];

        for (char c : chars) {
            curr.push_back(c);
            backtrack(digits, curr, i + 1);
            curr.pop_back();
        }
    }
};