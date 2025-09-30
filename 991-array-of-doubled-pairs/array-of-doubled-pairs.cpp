class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;

        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int i : arr) {
            freq[i]++;
        }

        for (int num : arr) {
            if (freq[num] == 0) continue;

            if (freq[num * 2] == 0) return false;

            freq[num]--;
            freq[num*2]--;
        }

        return true;
    }
};

/*

[4,-2,2,-4]

[-4:1, -2:1, 2:1, 4:1]


[3,1,3,6]

[3:2, 1:1, 6:1]

*/