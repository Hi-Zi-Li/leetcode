#include <vector>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i <  n; i++) {
        

        int toMove = nums[i];

        while (toMove > 0 && toMove <= n) {
            int tmp = nums[toMove-1];
            nums[toMove-1] = toMove;
            toMove = tmp;
            if (toMove <= 0 || toMove > n || toMove == nums[toMove-1])
                break;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ans)
            ans++;
        else
            break;
    }  
    return ans;  
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums) << endl;
    return 0;
}