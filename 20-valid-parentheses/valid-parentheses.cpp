// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for (char c : s) {
            switch (c) {
                case ')':
                    if (stck.empty() || stck.top() != '(') return false;
                    stck.pop();
                    break;
                case '}':
                    if (stck.empty() || stck.top() != '{') return false;
                    stck.pop();
                    break;
                case ']':
                    if (stck.empty() || stck.top() != '[') return false;
                    stck.pop();
                    break;
                default: stck.push(c);
            }
        }

        return stck.empty();
    }
};

/*


"([])"

]
[
(


*/