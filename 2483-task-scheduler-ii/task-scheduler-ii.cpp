class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> lastDay;
        long long day = 0;

        for (int task : tasks) {
            day++;

            if (lastDay.count(task)) {
                long long earliestDay = lastDay[task] + space + 1;
                day = max(day, earliestDay);
            }

            lastDay[task] = day;
        }

        return day;
    }
};