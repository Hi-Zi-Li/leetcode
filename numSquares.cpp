#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int numSquares(int n) {
    vector<int> dp(n+1, INT32_MAX);
    dp[0] = 0;
    int maxSqrt = sqrt(n);
    for (int i = 1; i <= maxSqrt; i++)
        dp[i*i] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) continue;
        int maxSqrtI = sqrt(i);
        for (int j = 1; j <= maxSqrtI; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n = 9;
    cout << numSquares(n) << endl;
    return 0;
}