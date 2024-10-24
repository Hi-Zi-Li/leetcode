#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool canPartition(vector<int> &nums) {
    int sum = 0;
    int n = nums.size();
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    if (sum % 2 != 0)
        return false;
    
    int target = sum / 2;
    if (maxNum > target)
        return false;
    vector<int> dp(target+1, 0);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] | dp[j-nums[i]];
        }
    }
    return dp[target];
}