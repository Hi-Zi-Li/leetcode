#include <string>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

string minWindow(string s, string t) {
    int slen = s.size(), tlen = t.size();
    if (slen < tlen) return "";
    int freq[58] = {};
    for (int i = 0; i < tlen; i++)
        freq[t[i] - 'A']++;
    vector<int> pos[58];
    string ans = "";
    for (int i = 0; i < slen; i++) {
        if (freq[s[i]-'A'] == 0)
            continue;
        pos[s[i]-'A'].push_back(i);
        bool ok = true;
        for (int j = 0; j < 58; j++) {
            if (pos[j].size() < freq[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int left = INT32_MAX;
            int leftChar = -1;
            for (int j = 0; j < 58; j++) {
                if (!pos[j].empty()) {
                    while (pos[j].size() > freq[j])
                        pos[j].erase(pos[j].begin());
                    if (pos[j][0] < left) {
                        left = pos[j][0];
                        leftChar = j;
                    }
                }
            }
            if (leftChar != -1)
                pos[leftChar].erase(pos[leftChar].begin());
            if (i-left+1 < ans.size() || ans == "")
                ans = s.substr(left, i-left+1);
        }
    }
    return ans;
}


int main() {
    cout << minWindow("abbdcadbcccabc", "abc") << endl;
    return 0;
}