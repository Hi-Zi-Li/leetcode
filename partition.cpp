#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
#include <chrono>
using namespace std;

unordered_map<string, set<vector<string>>> cache;
unordered_map<string, bool> isPalindrome;

set<vector<string>>& partition2set(string s) {
    if (cache.count(s))
        return cache[s];
    if (!isPalindrome.count(s)) {
        int n = s.size();
        isPalindrome[s] = true;
        for (int i = 0, j = n-1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                isPalindrome[s] = false;
                break;
            }
        }
    }
    if (isPalindrome[s]) {
        cache[s].insert({s});
    }
    for (int i = 1; i < s.size(); i++) {
        auto vvs1 = partition2set(s.substr(0, i));
        auto vvs2 = partition2set(s.substr(i, s.size()-i));
        for (auto vs1: vvs1) {
            for (auto vs2: vvs2) {
                vector<string> res(vs1.begin(), vs1.end());
                res.insert(res.end(), vs2.begin(), vs2.end());
                cache[s].insert(res);
            }
        }
    }
    return cache[s];
}

class Solution {
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; j++) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, false));
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
        }
        for (int i = 0; i < n; i++) {
            f[i][i+1] = (s[i] == s[i+1]);
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                int j = i+len-1;
                f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
            }
        }
        dfs(s, 0);
        return ret;
    }
};

int main() {
    auto start1 = chrono::high_resolution_clock::now();
    partition2set("aaaaaaaaaaaaaaaa");
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end1 - start1;
    cout << duration.count() << endl;
    auto start2 = chrono::high_resolution_clock::now();
    Solution().partition("aaaaaaaaaaaaaaaa");
    auto end2 = chrono::high_resolution_clock::now();
    duration = end2 - start2;
    cout << duration.count() << endl;
    // for (auto vs: vvs) {
    //     for (auto s: vs) {
    //         cout << s << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}