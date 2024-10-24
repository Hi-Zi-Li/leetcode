#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[100][100] = {};
        for (int i = 0; i < m; i++) {
            if (dp[0][i] == 0 && obstacleGrid[0][i] == 0) {
                dp[0][i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp[i][0] == 0 && obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
};
