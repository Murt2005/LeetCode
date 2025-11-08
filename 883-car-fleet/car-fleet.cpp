class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        int totalFleets = 0;
        vector<double> stck;
        for (const auto& car : cars) {
            stck.push_back((double)(target - car.first) / car.second);
            if (stck.size() >= 2 && stck.back() <= stck[stck.size() - 2]) {
                stck.pop_back();
            }
        }

        return stck.size();
    }
};

/*

given: a target mile, arr of its for intiial car positions, arr of ints for each car speed

return: the number of car fleets


target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

[{0,1}.{3,3},{5,1},{8,4},{10,2}]

2
2
7
3
12



hour 0: 10,8,0,5,3
hour 1: 12,12,1,6,6
hour 2: 12,12,2,7,7
hour 3: 

*/