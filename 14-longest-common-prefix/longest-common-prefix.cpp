class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || c != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(m) m = length of common prefix
//
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         sort(strs.begin(), strs.end());
//         string first = strs[0];
//         string last = strs[strs.size() - 1];

//         string result;
//         for (int i = 0; i < min(first.length(), last.length()); i++) {
//             if (first[i] == last[i]) {
//                 result.push_back(first[i]);
//             } else {
//                 break;
//             }
//         }

//         return result;
//     }
// };
