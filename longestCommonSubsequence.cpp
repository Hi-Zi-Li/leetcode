#include <string>
#include <vector>
#include <iostream>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (text1[i] == text2[j]) {
                dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (i == 0) ? (j == 0 ? 0 : dp[i][j - 1]) : (j == 0 ? dp[i - 1][j] : max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    // Test the function
    string text1 = "abcde", text2 = "abcdef";
    int result = longestCommonSubsequence(text1, text2);
    cout << "Length of longest common subsequence: " << result << endl;
    return 0;
}