class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];

        string result;
        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] == last[i]) {
                result.push_back(first[i]);
            } else {
                break;
            }
        }

        return result;
    }
};


/*

["flower", "flow", "flight"]

["flight", "flow", "flower"]




*/