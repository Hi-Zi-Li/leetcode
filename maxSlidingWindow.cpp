#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    // priority_queue<pair<int, int>> q;
    // for (int i = 0; i < k; i++) {
    //     q.emplace(nums[i], i);
    // }
    // res.push_back(q.top().first);
    // for (int i = k; i < nums.size(); i++) {
    //     while (q.top().second <= i - k && !q.empty()) {
    //         q.pop();
    //     }
    //     q.emplace(nums[i], i);
    //     res.push_back(q.top().first);
    // }
    // return res;

    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }    
    res.push_back(nums[dq.front()]);
    for (int i = k; i < n; i++) {
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        while (dq.front() <= i - k) {
            dq.pop_front();
        }
        res.push_back(nums[dq.front()]);
    }
}



int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(nums, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}