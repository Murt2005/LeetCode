class Solution {
public:
    string reorganizeString(string s) {
        string result;
        unordered_map<char, int> charCount; // maps char -> count
        priority_queue<pair<int, char>> pq;

        for (char c : s) {
            charCount[c]++;
        }

        for (auto& pair : charCount) {
            pq.push({pair.second, pair.first});
        }

        while (pq.size() > 1) {
            auto mostFrequent = pq.top();
            pq.pop();

            result += mostFrequent.second;

            auto secondFrequent = pq.top();
            pq.pop();

            result += secondFrequent.second;

            if (mostFrequent.first - 1 > 0) {
                pq.push({mostFrequent.first - 1, mostFrequent.second});
            }
            if (secondFrequent.first - 1 > 0) {
                pq.push({secondFrequent.first - 1, secondFrequent.second});
            }
        }

        if (!pq.empty()) {
            if (pq.top().first > 1) {
                return "";
            } else {
                result += pq.top().second;
            }
        }

        return result;
    }
};

/*

aab

[a:2], [b:1]




*/