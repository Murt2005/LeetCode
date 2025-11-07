class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalDays = (long long)m * k;
        if (totalDays > bloomDay.size()) {
            return -1;
        }
        
        int minDay = 1;
        int maxDay = 0;

        for (int day : bloomDay) {
            maxDay = max(maxDay, day);
        }

        while (minDay < maxDay) {
            int middleDay = (minDay + maxDay) / 2;
            int possibleBouquets = findPossibleBouquets(bloomDay, k, middleDay);
            if (possibleBouquets >= m) {
                maxDay = middleDay;
            } else {
                minDay = middleDay + 1;
            }
        }

        return minDay;
    }

private:
    int findPossibleBouquets(vector<int>& bloomDay, int k, int middleDay) {
        int possibleBouquets = 0;
        int count = 0;
        for (int day : bloomDay) {
            if (day <= middleDay) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                possibleBouquets++;
                count = 0;
            }
        }
        return possibleBouquets;
    }
};

/*

given:
- arr of int (bloomDay)
- int m (# of bouquets I want to make)
- int k (# of adjacent flowers I need to use from the garden)

ith flower will bloom on the bloomDay[i] and can be used ONLY ONCE to make a bouquet


return:
- min # of days I have to wait to make m bouquets from the garden
- if not possible to make m return -1


[1,10,3,10,2] m = 3, k = 1

output: 3


day 1: [x,_,_,_,_] can make 1
day 2: [x,_,_,_,x] can make two
day 3: [x,_,x_,x] can make 3



1 to 10 days

if i can x bouquets on day x I can make the same x bouquest on any day after x


left = 3, right = 3
middle = 2

[1,10,3,10,2]

////////////////////////////////

bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12

1 to 12 days

left = 12 right = 12
middle = 12

[7,7,7,7,12,7,7]


*/