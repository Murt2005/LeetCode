class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            if (firstList[i][1] >= secondList[j][0] && firstList[i][0] <= secondList[j][1]) {
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                result.push_back({start, end});
            }
            firstList[i][1] < secondList[j][1] ? i++ : j++;
        }
        return result;
    }
};