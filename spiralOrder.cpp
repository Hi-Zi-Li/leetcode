#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();
    int start_i = 0, start_j = 0;
    int end_i = row - 1, end_j = col - 1;
    int arrow = 0; // 0 right, 1 down, 2 left, 3 up
    int cnt = 0;
    while (cnt < row * col) {
        if (arrow == 0) {
            for (int j = start_j; j <= end_j; j++) {
                result.push_back(matrix[start_i][j]);
            }
            ++start_i;
            cnt += (end_j - start_j + 1);
            arrow = 1;
        } else if (arrow == 1) {
            for (int i = start_i; i <= end_i; i++) {
                result.push_back(matrix[i][end_j]);
            }
            cnt += (end_i - start_i + 1);
            --end_j;
            arrow = 2;
        } else if (arrow == 2) {
            for (int j = end_j; j >= start_j; j--) {
                result.push_back(matrix[end_i][j]);
            }
            cnt += (end_j - start_j + 1);
            --end_i;
            arrow = 3;
        } else if (arrow == 3) {
            for (int i = end_i; i >= start_i; i--) {
                result.push_back(matrix[i][start_j]);
            }
            cnt += (end_i - start_i + 1);
            ++start_j;
            arrow = 0;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}