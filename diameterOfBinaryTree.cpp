#include <unordered_map>
#include <vector>
#include "TreeNode.hpp"
#include <iostream>
using namespace std;

class Solution {
public:
    int len = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int hl = dfs(root->left);
        int hr = dfs(root->right);
        len = max(hl+hr , len);
        return max(hl, hr) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return len;
    }
};

class MySolution {
public:
    unordered_map<TreeNode*, int> depths;
    int maxEdges;

    MySolution(): depths(), maxEdges(0) {};

    int getDepth(TreeNode* root) {
        if (root == nullptr)
            return -1;
        if (depths.find(root) != nullptr)
            return depths[root];
        depths[root] = 1+ max(getDepth(root->left), getDepth(root->right));
        return depths[root];
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int edges = 0;
        if (root->left != nullptr) {
            edges += 1+getDepth(root->left);
            diameterOfBinaryTree(root->left);
        }
        if (root->right != nullptr) {
            edges += 1+getDepth(root->right);
            diameterOfBinaryTree(root->right);
        }
        maxEdges = max(edges, maxEdges);
        return maxEdges;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode* root = createTree(nums);
    Solution s;
    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}