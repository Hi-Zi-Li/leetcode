#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> edges[26];

vector<int> partitionLabels(string s) {
    int n = s.size();
    for (int i = 0; i < 26; i++) {
        edges[i] = {n, 0};
    }
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        edges[idx].first = min(edges[idx].first, i);
        edges[idx].second = max(edges[idx].second, i);
    }
    sort(edges, edges+26);
    vector<int> ans;
    int partition_left = edges[0].first, partition_right = edges[0].second;
    for (int i = 1; i < 26; i++) {
        if (edges[i].first == n)
            break;
        if (edges[i].first <= partition_right) {
            partition_right = max(partition_right, edges[i].second);
        } else {
            ans.push_back(partition_right - partition_left + 1);
            partition_left = edges[i].first;
            partition_right = edges[i].second;
        }
    }
    ans.push_back(partition_right - partition_left + 1);
    return ans;
}

int main() {
    string s = "ababcbacadefegdehijhklijz";
    vector<int> ans = partitionLabels(s);
    return 0;
}