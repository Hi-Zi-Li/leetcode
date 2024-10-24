// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int T;
//     int N,n,c;
//     vector<int> toys(500);
//     vector<int> dp(1000, 0);
//     cin >> T;
//     for (int _ = 0; _ < T; _++) {
//         for (int i = 0; i < 1000; i++)
//             dp[i] = 0;
//         cin >> N >> n >> c;
//         for (int i = 0; i < n; i++) {
//             cin >> toys[i];
//         }
//         sort(toys.begin(), toys.begin()+n);
//         for (int i = 0; i < n; i++) {
//             dp[toys[i]] = 1;
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < N; j++) {
//                 dp[j+toys[i]] |= dp[j];
//             }
//         }
//         for (int i = N; i >= N-c; i--)
//             if (dp[i] == 1) {
//                 cout << "YES\n";
//                 break;
//             } else if (i == N-c) {
//                 cout << "NO\n";
//             }
//     }
// }
 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int ii = 0; ii < T; ii++) {
        int n;
        cin >> n;
        vector<int> A(n);
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        bool lessSwap = true;
        vector<int> lessArr(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                lessArr[i] = min(A[i], B[i]);
            } else {
                lessArr[i] = min(A[i], B[i]);
                if (lessArr[i] < lessArr[i-1]) {
                    lessSwap = false;
                    break;
                }
            }
        }
        bool greaterSwap = true;
        vector<int> greaterArr(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                greaterArr[i] = max(A[i], B[i]);
            } else {
                greaterArr[i] = max(A[i], B[i]);
                if (greaterArr[i] > greaterArr[i-1]) {
                    greaterSwap = false;
                    break;
                }
            }
        }
        if (lessSwap || greaterSwap) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}