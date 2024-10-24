#include <vector>
#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    bitset<200> rows(0), cols(0);
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                rows.set(i);
                cols.set(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (rows.test(i)) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (cols.test(j)) {
            for (int i = 0; i < n; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}