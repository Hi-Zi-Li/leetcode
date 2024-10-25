#include "TreeNode.hpp"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// vector<int> inorderTraversal(TreeNode* root) {
//     if (root == nullptr) {
//         return {};
//     }
//     vector<int> vec;
//     stack<pair<TreeNode*, int>> s;
//     s.push({root, 0});
//     while (!s.empty()) {
//         auto &[node, visited] = s.top();
//         if (node->left == nullptr || visited) {
//             s.pop();
//             vec.push_back(node->val);
//             if (node->right != nullptr) {
//                 s.push({node->right, 0});
//             }
//         } else {
//             visited = 1;
//             s.push({node->left, 0});
//         }
//     }
//     return vec;
// }

vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<int> res;
    stack<TreeNode*> stk;
    while (!stk.empty() || root != nullptr) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    // node1->right = node2;
    // node2->left = node3;
    vector<int> ans = inorderTraversal(node1);
    return 0;
}