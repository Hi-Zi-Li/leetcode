#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<char>>& visited, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j] == 1)
        return;
    visited[i][j] = 1;
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i, j + 1);
    dfs(grid, visited, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> visited(n, vector<char>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0' || visited[i][j] == 1)
                continue;
            else {
                count++;
                dfs(grid, visited, i, j);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '0', '1'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'0', '0', '1', '1', '0'}
    };
    cout << numIslands(grid) << endl; // Output: 1
    return 0;
}