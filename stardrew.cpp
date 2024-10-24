#include <vector>
#include <iostream>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int sum = 0;
    vector<int> tops = {0};
    int i = 1;
    while (i < n) {
        while (i < n && height[i] < height[i-1]) {
            i++;
        }
        while (i < n && height[i] >= height[i-1]) {
            i++;
        }
        tops.push_back(i-1);
    }
    bool changed = true;
    while (changed && tops.size() > 2) {
        changed = false;
        for (int i = 1; i < tops.size()-1; i++) {
            if (height[tops[i]] <= height[tops[i-1]] && height[tops[i]] <= height[tops[i+1]]) {
                tops.erase(tops.begin() + i);
                i--;
                changed = true;
            }
        }
    }
    for (int i = 0; i < tops.size()-1; i++) {
        int minHeight = min(height[tops[i]], height[tops[i+1]]);
        for (int j = tops[i]+1; j < tops[i+1]; j++) {
            if (height[j] < minHeight)
                sum += minHeight - height[j];
        }
    }
    return sum;
}

int main() {
    vector<int> height = {4, 2, 0, 3, 1, 2, 0, 5};
    cout << trap(height) << endl;
    return 0;
}
