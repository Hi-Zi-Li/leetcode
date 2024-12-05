#include "TreeNode.hpp"
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        int n = nodes.size();
        ans.push_back({});
        for (int i = 0; i < n; i++) {
            TreeNode* tmp = nodes.front();
            ans.back().push_back(tmp->val);
            nodes.pop();
            if (tmp->left != nullptr)
                nodes.push(tmp->left);
            if (tmp->right != nullptr)
                nodes.push(tmp->right);
        }
    }
}