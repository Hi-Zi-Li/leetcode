#include "TreeNode.hpp"
#include <vector>
using namespace std;

TreeNode* createBSTNode(vector<int>& nums, int left, int right) {
    if (left > right)
        return nullptr;
    if (left == right)
        return new TreeNode(nums[left]);
    int mid = (left+right)/2;
    TreeNode* tmp = new TreeNode(nums[mid]);
    TreeNode* leftChild = createBSTNode(nums, left, mid-1);
    TreeNode* rightChild = createBSTNode(nums, mid+1, right);
    tmp->left = leftChild;
    tmp->right = rightChild;
    return tmp;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return nullptr;
    return createBSTNode(nums, 0, n-1);
}


int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    return 0;
}