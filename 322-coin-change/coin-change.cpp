class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);
        memo[0] = 0;
        return helper(coins, amount, memo);
    }

private:
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) {
            return -1;
        }
        
        if (memo[amount] != -2) {
            return memo[amount];
        }

        int minVal = INT_MAX;

        for (int coin : coins) {
            int result = helper(coins, amount - coin, memo);

            if (result != -1) {
                minVal = min(minVal, result + 1);
            }
        }

        memo[amount] = (minVal == INT_MAX) ? -1 : minVal;
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