class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack stores pairs of (character, count)
        vector<pair<char, int>> stack;
        
        for (char c : s) {
            // If stack is not empty and top character matches current
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
                // If count reaches k, remove this group
                if (stack.back().second == k) {
                    stack.pop_back();
                }
            } else {
                // New character, push with count 1
                stack.push_back({c, 1});
            }
        }
        
        // Build result string from stack
        string result;
        for (auto& p : stack) {
            result.append(p.second, p.first); // Append character p.second times
        }
        
        return result;
    }
};