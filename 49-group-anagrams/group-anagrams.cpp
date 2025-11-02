class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for (auto s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        for (auto pair : mp) {
            auto vec = pair.second;
            result.push_back(vec);
        }

        return result;
    }
};


/*

unordered_map<string, vector<string>> (maps sorted word to the word)



*/