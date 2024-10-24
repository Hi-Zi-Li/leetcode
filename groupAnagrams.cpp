#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<string, vector<string>> strMap; 
    for (auto str: strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        strMap[sortedStr].push_back(str);
    }
    vector<vector<string>> res;
    for (auto it = strMap.begin(); it != strMap.end(); ++it) {
        res.push_back(it->second);
    }
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(strs);
    for (auto &group: res) {
        for (auto &str: group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}