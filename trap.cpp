#include <vector>
#include <iostream>
using namespace std;


int trap0(vector<int>& height) {
    int sum = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (leftMax < rightMax) {
            sum += leftMax - height[left];
            left++;
        } else {
            sum += rightMax - height[right];
            right--;
        }
    }
    return sum;
}

int trap1(vector<int>& height) {
    vector<int> left;
    int sum = 0;
    for (int i = 0; i < height.size(); i++) {
        if (left.empty()) {
            left.push_back(height[i]);
        } else if (left.back() < height[i]) {
            left.push_back(height[i]);
        } else {

        }
    }
    return sum;
}

int trap2(vector<int>& height) {
    int sum = 0;
    vector<int> stk;
    int n = height.size();
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && height[i] > height[stk.back()]) {
            int top = stk.back();
            stk.pop_back();
            if (stk.empty()) {
                break;
            }
            int left = stk.back();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            sum += currWidth * currHeight;
        }
        stk.push_back(i);
    }
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap1(height) << endl;
    return 0;
}