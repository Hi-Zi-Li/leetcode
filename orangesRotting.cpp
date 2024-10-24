#include <vector>
#include <iostream>
using namespace std;

int minutes = 0;


inline bool setRotting(vector<vector<int>>& grid, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
        grid[i][j] = 3+minutes;
        return 1;
    }
    return 0;
}

int orangesRotting(vector<vector<int>>& grid) {
    int changed = 1;
    int n = grid.size();
    int m = grid[0].size();
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2+minutes) {
                    changed |= setRotting(grid, i + 1, j);
                    changed |= setRotting(grid, i - 1, j);
                    changed |= setRotting(grid, i, j + 1);
                    changed |= setRotting(grid, i, j - 1);
                }
            }
        }
        if (changed)
            minutes++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                minutes = -1;
                break;
            }
        }
    }
    return minutes;
}

int main() {
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}