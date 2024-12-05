#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;

bool merge(vector<TreeNode*>& nodes, TreeNode*& node1, TreeNode*& node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;
    if ((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr))
        return false;
    if (node1->val == node2->val) {
        nodes.push_back(node1);
        nodes.push_back(node2);
        return true;
    }
    return false;
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    vector<TreeNode*> nodes = {root->left, root->right};
    while (!nodes.empty()) {
        int n = nodes.size();
        if (n % 2 != 0)
            return false;
        for (int i = 0; i < n; i+=2) {
            if (!merge(nodes, nodes[i]->left, nodes[i+1]->right) || !merge(nodes, nodes[i]->right, nodes[i+1]->left))
                return false;
        }
        nodes.erase(nodes.begin(), nodes.begin()+n);
    }
    return true;
}



int main() {
    vector<int> nums = {1,2,2,-1,3,-1,3};
    TreeNode* root = createTree(nums);
    cout << isSymmetric(root) << endl;
    return 0;
}