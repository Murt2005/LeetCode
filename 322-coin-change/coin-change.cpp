class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo; // amount -> min coins
        return helper(coins, amount, memo);
    }

private:
    int helper(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int minCoins = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int result = helper(coins, amount - coins[i], memo);

            if (result != -1) {
                minCoins = min(minCoins, result + 1);
            }
        }

        memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[amount];
    }
};


/*

for each coin I have coins.length() options to pick from
i can add more of my current coin, or add more of another coin
for each option I can recursively subtract from the total and then add to the total number of coins I am using
if the total reaches below 0 then we can not call the helper function
if the total hits 0, we can return the value found for the number of coins
we want to take the min




*/