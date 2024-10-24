#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {
public:
    vector<int> arr;

    MedianFinder() {
        arr.clear();
    }
    
    void addNum(int num) {
        if (arr.empty()) {
            arr.push_back(num);
            return;
        }
        int n = arr.size();
        int l = 0, r = n - 1;
        int mid = n / 2;
        while (l < r) {
            mid = (l + r)/2;
            if (num < arr[mid]) {
                r = mid - 1;
            } else if (num == arr[mid]) {
                arr.insert(arr.begin() + mid, num);
                return;
            } else {
                l = mid + 1;
            }
        }
        if (num < arr[l]) {
            arr.insert(arr.begin() + l, num);
        } else {
            arr.insert(arr.begin() + l + 1, num);
        }
    }
    
    double findMedian() {
        int n = arr.size();
        if (n % 2 == 0) {
            return (arr[n/2] + arr[n/2 - 1]) / 2.0;
        } else {
            return arr[n/2];
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 3.0
}