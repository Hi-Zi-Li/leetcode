#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])) ? true : false;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (auto &interval: intervals) {
        if (interval[0] > right) {
            ans.push_back({left, right});
            left = interval[0];
        }
        right = max(right, interval[1]);
    }
    if (ans.empty() || (ans.back()[0] != left || ans.back()[1] != right)) {
        ans.push_back({left, right});
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    vector<vector<int>> merged = merge(intervals);
    for (auto &v: merged) {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}