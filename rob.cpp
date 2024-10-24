#include <vector>
#include <iostream>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    int max1 = nums[0];
    int max2 = max(max1, nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        int temp = max2;
        max2 = max(max2, max1 + nums[i]);
        max1 = temp;
    }
    return max2;
}

int main() {
    vector<int> nums = {9, 4, 6, 10};
    cout << rob(nums) << endl; // Output: 12
    return 0;
}