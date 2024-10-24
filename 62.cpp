#include <unordered_map>
#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    static std::unordered_map<int, int> memo;
    int key = (m<<16) | n;
    if (memo.count(key))
        return memo[key];
    if (m==1 || n==1) {
        memo.emplace(key, 1);
        return 1;
    }
    int res = uniquePaths(m-1, n) + uniquePaths(m, n-1);
    memo.emplace(key, res);
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}