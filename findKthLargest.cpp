#include <vector>
#include <iostream>

using namespace std;

void maxHeapify(vector<int>&nums, int i, int heapSize) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int largest = i;
    if (l < heapSize && nums[l] > nums[largest])
        largest = l;
    if (r < heapSize && nums[r] > nums[largest])
        largest = r;
    if (largest != i) {
        swap(nums[i], nums[largest]);
        maxHeapify(nums, largest, heapSize);
    }
}

void buildMaxHeap(vector<int> &nums, int heapSize) {
    for (int i = heapSize / 2; i >=0; i--) {
        maxHeapify(nums, i, heapSize);
    }
}

int findKthLargest(vector<int> &nums, int k) {
    int heapSize = k;
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size()-1; i >= nums.size()-k+1; i--) {
        swap(nums[0], nums[i]); // 将最大的元素放到最后
        --heapSize;
        maxHeapify(nums, 0, heapSize); // 重新调整堆
    }
    return nums[0];
}

// int quickselect(vector<int> &nums, int l, int r, int k) {
//     if (l == r)
//         return nums[k];
//     int partition = nums[l], i = l - 1, j = r + 1;
//     while (i < j) {
//         do i++; while (nums[i] < partition);
//         do j--; while (nums[j] > partition);
//         if (i < j)
//             swap(nums[i], nums[j]);
//     }
//     if (k <= j)return quickselect(nums, l, j, k);
//     else return quickselect(nums, j + 1, r, k);
// }

// int findKthLargest(vector<int> &nums, int k) {
//     int n = nums.size();
//     return quickselect(nums, 0, n - 1, n - k);
// }


int main() {
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 1) << endl;
}