#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> substrVisited;
bool wordBreak(string s, vector<string>& wordDict) {
    int slen = s.size();
    for (auto& word: wordDict) {
        int i = 0;
        int wordlen = word.size();
        for (; i < wordlen; i++) {
            if (s[i] != word[i]) {
                break;
            }
        }
        if (i == wordlen) {
            auto it = substrVisited.find(s.substr(i));
            if (it == substrVisited.end()) {
                substrVisited[s.substr(i)] = 0;
            }
            if (i == slen)
                return true;
        }
    }
    for (auto &[substr, visited]: substrVisited) {
        if (!visited) {
            visited++;
            if (wordBreak(substr, wordDict)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s = "abcdefg";
    vector<string> wordDict = {"abcde","cdef","fg","bcde","a"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}