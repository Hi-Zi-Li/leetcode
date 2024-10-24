#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    vector<bool> b(n+1);
    for (int i = 0; i < nums.size(); i++) {
        if (b[nums[i]]) {
            return nums[i];
        }
        b[nums[i]] = 1;
    }
}