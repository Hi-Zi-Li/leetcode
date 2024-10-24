#include <vector>
#include <iostream>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> dp(n);
    dp[0] = {nums[0], nums[0]};
    for (int i = 1; i < n; i++) {
        if (nums[i] >= 0) {
            dp[i].first = max(nums[i], dp[i-1].first * nums[i]);
            dp[i].second = min(nums[i], dp[i-1].second * nums[i]);
        } else {
            dp[i].first = max(nums[i], dp[i-1].second * nums[i]);
            dp[i].second = min(nums[i], dp[i-1].first * nums[i]);
        }
    }
    int product = dp[0].first;
    for (int i = 0; i < n; i++) {
        product = max(product, dp[i].first);
    }
    return product;
}


int main() {
    vector<int> nums = {2, 3, -2, 3, 5, -4};
    cout << maxProduct(nums) << endl;
}