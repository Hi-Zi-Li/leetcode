#include <vector>
#include <iostream>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount+1, 0xffff000);
    for (auto &coin: coins) {
        if (coin > amount) continue;
        dp[coin] = 1;        
    }
    for (int i = 1; i <= amount; i++) {
        if (dp[i] == 1) continue;
        for (auto &coin: coins) {
            if (i < coin)   continue;
            dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    if (dp[amount] > amount) return -1;
    return dp[amount];
}

int main() {
    vector<int> coins = {2};
    int amount = 1;
    cout << coinChange(coins, amount) << endl;
}