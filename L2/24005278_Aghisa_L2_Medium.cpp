/*
 ID: 24005278
 Name: Aghisa Zahra
 Group: G2
 Lab: L2 (Medium) - Rotate Square Matrix by 90 Degrees Counterclockwise
 Problem: https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate90(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    
    for (auto& row : matrix)
        reverse(row.begin(), row.end());
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}

int main() {
    
    vector<vector<int>> matrix = {
        {18, 76, 58},
        {17, 28, 45},
        {75, 39, 29}
    };

    rotate90(matrix);
    printMatrix(matrix);

    return 0;
}


