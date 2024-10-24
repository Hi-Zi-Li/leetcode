#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    auto it = nums.begin();
    int size = nums.size();
    int idx = 0;
    while (idx < size) {
        if (*it == 0) {
            it = nums.erase(it);
            nums.push_back(0);
        } else {
            it++;
        }
        idx++;
    }

    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++j;
        }
    }
}


int main() {
    vector<int> nums = {0,1,0,0,3,12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}