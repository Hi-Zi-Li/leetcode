#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int ans = INT32_MIN;
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (sum + nums[i] < nums[i])
            sum = nums[i];
        else
            sum += nums[i];
        ans = max(ans, sum);
    }
    return ans;
}

struct Status {
    int lSum, rSum, mSum, iSum;
};

Status pushUp(Status l, Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = max(l.lSum, l.iSum + r.lSum);
    int rSum = max(r.rSum, r.iSum + l.rSum);
    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
    return (Status) {lSum, rSum, mSum, iSum};
}

Status get(vector<int>& a, int l, int r) {
    if (l == r)
        return (Status) {a[l], a[l], a[l], a[l]};
    int m = (l + r) / 2;
    Status lSub = get(a, l, m);
    Status rSub = get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int main() {
    vector<int> nums = {-2, -1};
    cout << maxSubArray(nums) << endl; // Output: 6
}
