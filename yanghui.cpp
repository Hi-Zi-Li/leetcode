#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result = {{1}};
    for (int i = 1; i < numRows; i++) {
        result.push_back({1});
        for (int j = 0; j < i-1; j++) {
            result[i].push_back(result[i-1][j] + result[i-1][j+1]);
        }
        result[i].push_back(1);
    }
    return result;
}

int main() {
    vector<vector<int>> result = generate(3);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}