#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    vector<int> w, v;
    vector<int> f;
    int V, n;
    while (cin>>V>>n) {
        w.clear();
        v.clear();
        f.clear();
        w.push_back(0);
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            int cur_w, cur_v;
            cin >> cur_w >> cur_v;
            w.push_back(cur_w);
            v.push_back(cur_v);
        }
        f = vector<int>(V+1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = V; j >= w[i]; j--) {
                f[j] = max(f[j], f[j-w[i]] + v[i]);
            }
        }
    }
}