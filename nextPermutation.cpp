#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int bgn = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            bgn = i;
            break;
        }
    }
    if (bgn == n - 1) {
        reverse(nums.begin(), nums.end());
        return;
    } else {
        for (int i = n-1; i > bgn; i--) {
            if (nums[i] > nums[bgn]) {
                swap(nums[i], nums[bgn]);
                reverse(nums.begin()+bgn+1, nums.end());
                return;
            }
        }
    }
}


int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}