#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end())
        return nums.size();
    return distance(nums.begin(), it);
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 1)
        return (nums[0]==target) ? 0: -1;
    int l = 0, r = n-1;
    int first = nums[0];
    while (l <= r) {
        int mid = (l+r)/2;
        if (nums[mid] > first) {
            l = mid+1;
        } else if (nums[mid] == first) {
            r = (nums[mid] > nums[mid+1])? mid : mid+1;
            break;
        } else {
            r = mid-1;
        }
    }
    int k = n - r - 1;
    l = 0, r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int i = mid>=k ? mid-k : n-k+mid;
        if (nums[i] > target) {
            r = mid-1;
        } else if (nums[i] == target) {
            return i;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2};
    cout << search(nums, 1);
    // cout << searchInsert(nums, 4);
}