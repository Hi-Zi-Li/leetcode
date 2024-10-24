#include <vector>
#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int tmp00, tmp01, tmp10, tmp11;
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < (n+1)/2; j++) {
            tmp00 = matrix[i][j];
            tmp01 = matrix[j][n-1-i];
            tmp11 = matrix[n-1-i][n-1-j];
            tmp10 = matrix[n-1-j][i];
            
            matrix[i][j] = tmp10;
            matrix[j][n-1-i] = tmp00;
            matrix[n-1-i][n-1-j] = tmp01;
            matrix[n-1-j][i] = tmp11;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1}};
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}