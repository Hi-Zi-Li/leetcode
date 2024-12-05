#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& combine, int target, int idx) {
    if (idx == candidates.size() || target < 0)
        return;
    if (target == 0) {
        ans.push_back(combine);
        return;
    }
    dfs(ans, candidates, combine, target, idx+1);
    combine.push_back(candidates[idx]);
    dfs(ans, candidates, combine, target-candidates[idx], idx);
    combine.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combination;
    dfs(ans, candidates, combination, target, 0);
    return ans;
}