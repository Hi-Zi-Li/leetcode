#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {7,7,7,7,7,7,7};
    int res = lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}