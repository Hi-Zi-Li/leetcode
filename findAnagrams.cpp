#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int plen = p.size();
    int slen = s.size();
    if (slen < plen)
        return {};
    vector<int> res;
    int freq[26] = {0};
    vector<int>curr[26];
    int currChars = 0;
    for (int i = 0; i < plen; i++) {
        freq[p[i]- 'a']++;
    }
    
    for (int i = 0; i < slen; i++) {
        if (freq[s[i]-'a'] == 0) {
            for (int j = 0; j < 26; j++)
                curr[j].clear();
            currChars = 0;
        } else {
            if (curr[s[i]-'a'].size() >= freq[s[i]-'a']) {
                int del = curr[s[i]-'a'].front();
                for (int j = 0; j < 26; j++) {
                    auto it = curr[j].begin();
                    while (it != curr[j].end()) {
                        if (*it <= del) {
                            it = curr[j].erase(it);
                            currChars--;
                        } else {
                            break;
                        }
                    }
                }
            }
            curr[s[i]-'a'].push_back(i);
            currChars++;
            if (currChars == plen) {
                int bgn = 0xffffff;
                for (int k = 0; k < 26; k++) {
                    if (curr[k].size() > 0)
                        bgn = min(bgn, curr[k][0]);
                }
                if (bgn != 0xffffff)
                    res.push_back(bgn);
            }
        }
    }
    return res;

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i = 0; i < p.size(); i++) {
        pCount[p[i] - 'a']++;
        sCount[p[i] - 'a']++;
    }
    for (int i = 0; i <= s.size() - p.size(); i++) {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + p.size()] - 'a'];
        if (sCount == pCount) {
            ans.push_back(i);
        }
    }
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s, p);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}