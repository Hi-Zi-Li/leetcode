#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> locations;
vector<vector<string>> ret;
int n;

vector<bool> visitedRow;
vector<bool> visitedCol;
vector<bool> visitedDiag1;
vector<bool> visitedDiag2;

void setVisited(int x, int y) {
    visitedRow[x] = true;
    visitedCol[y] = true;
    visitedDiag1[x - y + n - 1] = true;
    visitedDiag2[x + y] = true;
}

void resetVisited(int x, int y) {
    visitedRow[x] = false;
    visitedCol[y] = false;
    visitedDiag1[x - y + n - 1] = false;
    visitedDiag2[x + y] = false;
}

void place(int i) {
    if (i == n) {
        vector<string> ans(n, string(n, '.'));
        for (auto [i, j] : locations)
            ans[i][j] = 'Q';
        ret.push_back(ans);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!visitedRow[i] && !visitedCol[j] && !visitedDiag1[i - j + n - 1] && !visitedDiag2[i + j]) {
            setVisited(i, j);
            locations.push_back({i, j});
            place(i + 1);
            locations.pop_back();
            resetVisited(i, j);
        }
    }
}

vector<vector<string>> solveNQueens(int m) {
    n = m;
    visitedRow.assign(n, false);
    visitedCol.assign(n, false);
    visitedDiag1.assign(2 * n - 1, false);
    visitedDiag2.assign(2 * n - 1, false);
    place(0); 
    return ret;
}


int main() {
    int n = 8;
    auto ans = solveNQueens(n);
    for (auto v: ans) {
        for (auto s: v)
            cout << s << " ";
        cout << endl;
    }
}