class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for (char c : s) {
            if (closeToOpen.count(c) && !stck.empty() && stck.top() == closeToOpen[c]) {
                stck.pop();
            } else if (closeToOpen.count(c) && !stck.empty() && stck.top() != closeToOpen[c]) {
                return false;
            } else {
                stck.push(c);
            }
        }

        return stck.empty();
    }

private:
    unordered_map<char, char> closeToOpen = {
        {')', '('}
        , {'}', '{'}
        , {']', '['}
    };
};

/*


"([])"

]
[
(


*/