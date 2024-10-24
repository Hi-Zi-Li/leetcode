#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string ans = s.substr(0, 1);
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            ans = s.substr(i, 2);
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i+len-1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (ans.size() < len)
                    ans = s.substr(i, len);
            }
        }
    }
    return ans;
}

int main() {
    // Test cases
    cout << longestPalindrome("babad") << endl; // Output: "bab"
    cout << longestPalindrome("cbbc") << endl; // Output: "bb"
}