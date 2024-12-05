#include <vector>
#include <stack>
#include "TreeNode.hpp"
using namespace std;

int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr)
        return -1;
    stack<TreeNode*> stk;
    int n = 1, i = 0;
    int val = root->val;
    stk.push(root);
    while (!stk.empty() ) {
        while (root != nullptr && root->left != nullptr) {
            stk.push(root->left);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        i++;
        if (i == k)
            return root->val;
        root = root->right;
        if (root != nullptr)
            stk.push(root);
    }
    return -1;
}


int main() {
    vector<int> nums = {2, 1, 3};
    TreeNode* root = createTree(nums);
    int val = kthSmallest(root, 3);
    return val;
}