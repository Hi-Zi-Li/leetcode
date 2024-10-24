#include <vector>
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty())
        return 0;
    sort(nums.begin(), nums.end());
    int cnt = 1;
    int maxCnt = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] == nums[i]) {
            continue;
        } else if (nums[i-1] + 1 == nums[i]) {
            cnt++;
        } else {
            if (cnt > maxCnt)
                maxCnt = cnt;
            cnt = 1;
        }
    }
    if (cnt > maxCnt)
        maxCnt = cnt;
    return maxCnt;
}

int main() {
    vector<int>nums = {100,4,200,1,3,2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}
