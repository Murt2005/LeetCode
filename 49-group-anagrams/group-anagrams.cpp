class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for (string s : strs) {
            string temp = s;
            sort(s.begin(), s.end());
            anagrams[s].push_back(temp);
        }

        for (const auto& [sorted, strings] : anagrams) {
            result.push_back(strings);
        }

        return result;
    }
};



/*

["eat","tea","tan","ate","nat","bat"]


algorithm:
- use an unordered_map<string, vector<string>> anagrams which maps ordered string to the possible anagrams from ordered string
- loop through strs and sort each strs[i] and assign anagrams[sorted(strs[i])].push_back(strs[i])
- then loop through the map and put the result into vector<vector<string>> output

*/