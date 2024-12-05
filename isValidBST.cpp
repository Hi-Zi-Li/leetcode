#include "TreeNode.hpp"
#include <queue>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

struct nodeRange {
    int valMin, valMax, isValid;
};


nodeRange getTreeValRange(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr)
        return nodeRange{root->val, root->val, 1};
    int valMin = root->val, valMax = root->val;

    if (root->left != nullptr) {
        nodeRange leftInfo = getTreeValRange(root->left);
        if (!leftInfo.isValid || leftInfo.valMax >= root->val)
            return nodeRange{INT_MIN, INT_MAX, 0};
        valMin = min(leftInfo.valMin, valMin);
    }
    if (root->right != nullptr) {
        nodeRange rightInfo = getTreeValRange(root->right);
        if (!rightInfo.isValid || rightInfo.valMin <= root->val)
            return nodeRange{INT_MIN, INT_MAX, 0};
        valMax = max(rightInfo.valMax, root->val);
    }
    return nodeRange{valMin, valMax, 1};
}

bool isValidBST(TreeNode* root) {
    if (root == nullptr)
        return true;
    return getTreeValRange(root).isValid;
}

bool helper(TreeNode* root, long long lower, long long upper) {
    if (root == nullptr) {
        return true;
    }
    if (root->val <= lower || root->val >= upper)
        return false;
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

bool inorderTraserval(TreeNode* root) {
    if (root == nullptr)
        return true;
    stack<TreeNode*> stk;
    stk.push(root);
    long long inorder = LONG_MIN;
    while (!stk.empty()) {
        while (root != nullptr) {
            stk.push(root->left);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val <= inorder)
            return false;
        inorder = root->val;
        root = root->right;
    }
    return true;
}

int main() {
    vector<int> nums = {5,1,4,-1,-1,3,6};
    TreeNode* root = createTree(nums);
    bool result = isValidBST(root);
    return 0;
}

// bool isValidBST(TreeNode* root) {
//     if (root == nullptr)
//         return true;
//     int gt = 1;
//     queue<TreeNode*> nodes;
//     nodes.push(root); 
//     while (!nodes.empty()) {
//         int n = nodes.size();
//         for (int i = 0; i < n; i++) {
//             TreeNode* tmp = nodes.front();
//             nodes.pop();
//             if (tmp->left != nullptr)
//                 nodes.push(tmp->left);
//             if (tmp->right != nullptr)
//                 nodes.push(tmp->right);
//         }
//         gt *= 2;
//         if (nodes.size() != gt) {
//             while (!nodes.empty()) {
//                 if (nodes.front()->left != nullptr || nodes.front()->right != nullptr)
//                     return false;
//                 nodes.pop();
//             }
//             return true;
//         }
//     }
//     return true;
// }