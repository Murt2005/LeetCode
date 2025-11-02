class Solution {
private:
    void backtrack(int openN, int closedN, vector<string>& result, string s, int n) {
        if (openN == closedN && s.length() == n * 2) {
            result.push_back(s);
            return;
        }

        if (openN < n) {
            s.push_back('(');
            backtrack(openN + 1, closedN, result, s, n);
            s.pop_back();
        }

        if (closedN < openN) {
            s.push_back(')');
            backtrack(openN, closedN + 1, result, s, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        s.reserve(2 * n);
        backtrack(0, 0, result, s, n);
        return result;
    }
};