class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                result[prevIdx] = i - prevIdx;
            }
            st.push(i);
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