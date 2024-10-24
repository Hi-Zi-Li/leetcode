#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int subarraySum(std::vector<int>& nums, int k) {
    vector<int> prefixSum(nums.size()+1, 0);
    unordered_map<int, int> sumCnt = {{0, 1}};
    for (int i = 0; i < nums.size(); i++) {
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }
    int cnt = 0;
    for (int i = 1; i < prefixSum.size(); i++) {
        int target = prefixSum[i] - k;
        auto it = sumCnt.find(target);
        if (it != sumCnt.end()) {
            cnt += it->second;
        }
        sumCnt[prefixSum[i]]++;
    }
    return cnt;
}

int main() {
    vector<int> nums = {2, 1, 2, 5, 6, 7, 8, 9, 10};
    int k = 10;
    cout << subarraySum(nums, k) << endl; // Output: 2
}