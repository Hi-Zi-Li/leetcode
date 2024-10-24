#include <vector>
using namespace std;

int maxKilledEnemies(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0) return 0;
    int dp[100][100] = {};
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0')
                dp[i][j] += pre;
            else if (grid[i][j] == 'E')
                ++pre;
            else
                pre = 0;
        }
    }

    pre = 0;
    for (int i = 0; i < n; i++) {
        pre = 0;
        for (int j = m-1; j >= 0; j--) {
            if (grid[i][j] == '0')
                dp[i][j] += pre;
            else if (grid[i][j] == 'E')
                ++pre;
            else
                pre = 0;
        }
    }

    pre = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '0')
                dp[j][i] += pre;
            else if (grid[j][i] == 'E')
                ++pre;
            else
                pre = 0;
        }
    }
}
