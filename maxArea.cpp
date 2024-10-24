#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int size = height.size();
    int i = 0;
    int j = size - 1;
    int area = min(height[i], height[j]) * (j - i);
    while (i != j) {
        if (height[i] <= height[j]) {
            i++;
        } else {
            j--;
        }
        area = max(area, min(height[i], height[j]) * (j - i));
    }
    return area;
}

int main() {
    vector<int> height = {1,0,0,0,0,0,0,2,2};
    cout << maxArea(height) << endl;
    return 0;
}