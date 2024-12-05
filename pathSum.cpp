#include <unordered_map>
#include "TreeNode.hpp"
using namespace std;

unordered_map<long long, int> prefix;

int dfs(TreeNode* root, long long curr, int targetSum) {
    if (root == nullptr)
        return 0;
    int ret = 0;
    curr += root->val;
    if (prefix.count(curr-targetSum)) {
        ret = prefix[curr-targetSum];
    }
    prefix[curr]++;
    ret += dfs(root->left, curr, targetSum);
    ret += dfs(root->right, curr, targetSum);
    prefix[curr]--;
    return ret;
}

int pathSum(TreeNode* root, long long targetSum) {
    if (root == nullptr)
        return 0;
    prefix[0] = 1;
    return dfs(root, 0, targetSum);   
}