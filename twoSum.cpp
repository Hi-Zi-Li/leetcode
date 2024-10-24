#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> indices;
vector<int> twoSum(vector<int>& nums, int target) {
    indices.resize(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), 
        [&](const int &a, const int &b) {
            return nums[a] < nums[b];
        }
    );

    sort(nums.begin(), nums.end());
    int left = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] > (float)target/2)
            break;
        if (nums[i] == (float)target/2) {
            left = i;
            break;
        }
        left = i;
    }
    int right = left + 1;
    bool leftMove = false, rightMove = false;
    while (left >= 0 && right < size) {
        if (nums[left] + nums[right] == target)
            return {left, right};
        else if (nums[left] + nums[right] > target)
            left--;
        else
            right++;
    }
    return {};
}

int main() {
    vector<int> nums = {-3, -1, 4, 3, 0};
    int target = -1;
    vector<int> res = twoSum(nums, target);
    cout << indices[res[0]] << " " << indices[res[1]] << endl;
    return 0;
}