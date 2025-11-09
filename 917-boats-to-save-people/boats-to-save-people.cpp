class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int minBoats = 0;
        int left = 0;
        int right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }

            minBoats++;
            right--;
        }
        return minBoats;
    }
};

/*

[1,2,2,3,4,5] limit = 7
     ^ ^

minBoat = 3
currentWeight = 6



*/