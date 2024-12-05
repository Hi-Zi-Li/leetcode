#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int k = 0;
    for ( ; left <= right; ) {
        int mid = (left + right) / 2;
        if (nums[0] <= nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return (right == nums.size()-1) ? nums[0]: nums[right+1];
}

int main() {
    vector<int> nums = {2, 3, -1, 0, 1};
    cout << findMin(nums) << endl;
}