#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto &num: nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> ans;
        vector<int> result; 
        for (auto [num, cnt]: freq) {
            ans.push({cnt, num});
        }
        
        for (int i = 0; i < k; i++) {
            result.push_back(ans.top().second);
            ans.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result = s.topKFrequent(nums, 2);
    for (auto &num: result) {
        cout << num << " ";
    }
    cout << endl;
}