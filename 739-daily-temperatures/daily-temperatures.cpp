class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                auto val = st.top();
                st.pop();
                result[val.second] = i - val.second;
            }
            st.push({temperatures[i], i});
        }

        while (!st.empty()) {
            auto val = st.top();
            st.pop();
            result[val.second] = 0;
        }

        return result;
    }
};


/*

[73,74,75,71,69,72,76,73]

76
72
69
71
75

[1,1,]

*/