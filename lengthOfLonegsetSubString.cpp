#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int tmp = 0;
    int freq[256];
    memset(freq, -1, sizeof(freq));
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == -1) {
            freq[s[i]] = i;
            tmp++;
        } else {
            ans = max(ans, tmp);
            for (int j = 0; j < 256; j++) {
                if (freq[j] < freq[s[i]]) {
                    freq[j] = -1;
                }
            }
            tmp = i - freq[s[i]];
            freq[s[i]] = i;
        }
    }
    ans = max(ans, tmp);
    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcdabc") << endl;
    return 0;
}