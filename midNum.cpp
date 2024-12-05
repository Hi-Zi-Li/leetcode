#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int getMidNum(vector<int>& A, vector<int>& B, int n) {
    if (n == 1)
        return min(A[0], B[0]);
    int bgnA = 0, endA = n-1;
    int bgnB = 0, endB = n-1;
    int midA = (endA + bgnA)/2;
    int midB = (endB + bgnB)/2;
    while (bgnA != endA && bgnB != endB) {
        if (A[midA] == B[midB]) {
            return A[midA];
        }
        if (A[midA] < B[midB]) {
            bgnA = midA;
            endB = midB;
        } else {
            endA = midA;
            bgnB = midB;
        }
        midA = (endA + bgnA)/2;
        midB = (endB + bgnB )/2;
    }
    if (bgnA == endA) {
        return min(A[midA], B[midB+1]);
    }
    return min(B[midB], A[midA+1]);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int left = 0, right = m;
    while (left <= right) {
        int partition1 = (left + right)/2;
        int partition2 = (n+m+1)/2 - partition1;
        int maxLeft1 = (partition1 == 0)? INT_MIN: nums1[partition1-1];
        int minRight1 = (partition1 == m)? INT_MAX: nums1[partition1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN: nums2[partition2-1];
        int minRight2 = (partition2 == n)? INT_MAX: nums2[partition2];
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m+n)%2 == 1) {
                return max(maxLeft1, maxLeft2);
            } else {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }
}

int main() {
    int n = 5;
    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    cout << getMidNum(A, B, n) << endl;
    return 0;
}