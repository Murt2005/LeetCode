class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs) {
            string key = getKey(s);
            mp[key].push_back(s);
        }

        for (auto& [key, vec] : mp) {
            result.push_back(std::move(vec));
        }

        return result;
    }

private:
    string getKey(const string& s) {
        vector<int> count(26,0);
        
        for (char c : s) {
            count[c - 'a']++;
        }

        string key;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                key += string(count[i], i + 'a');
            }
        }

        return key;
    }
};



// Time Complexity: O(N * klogk) where k is the max length of a string
// Space Complexity: O(N)
//
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;
//         unordered_map<string, vector<string>> mp;

//         for (const auto& s: strs) {
//             string temp = s;
//             sort(temp.begin(), temp.end());
//             mp[temp].push_back(s);
//         }

//         for (auto& [key, vec] : mp) {
//             result.push_back(vec);
//         }

//         return result;
//     }
// };
