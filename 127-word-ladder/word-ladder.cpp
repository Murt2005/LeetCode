class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        unordered_set<string> visited;
        queue<string> q;
        visited.insert(beginWord);
        q.push(beginWord);

        int minOperations = 0;

        while (!q.empty()) {
            minOperations++;
            int qSize = q.size();
            for (int s = 0; s < qSize; s++) {
                auto word = q.front();
                q.pop();

                if (word == endWord) {
                    return minOperations;
                }

                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) {
                            continue;
                        }
                        word[i] = c;

                        if (wordSet.count(word) && !visited.count(word)) {
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};


/*

algorithm:
- 


*/