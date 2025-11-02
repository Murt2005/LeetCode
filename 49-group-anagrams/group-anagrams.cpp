class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for (const auto& s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        for (auto& [key, vec] : mp) {
            result.push_back(vec);
        }

        return result;
    }
};

// Time Complexity: O(N * klogk) where k is the max length of a string
// Space Complexity: O(N)


/*

unordered_map<string, vector<string>> (maps sorted word to the word)



*/