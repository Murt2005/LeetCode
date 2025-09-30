class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> freq;
        int pairs = 0;
        for (int i = 0; i < time.size(); i++) {
            int remainder = time[i] % 60;
            int complement = (60 - remainder) % 60;

            if (freq.contains(complement)) {
                pairs += freq[complement];
            }

            freq[remainder]++;
        }

        return pairs;
    }
};

/*


[30,20,150,100,40]

[30,20,30,40,40]

[20:1, 30:2, 40:2]



*/