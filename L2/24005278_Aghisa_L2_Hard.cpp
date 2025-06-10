/*
id: 24005278
name: Aghisa
group: G2
lab: L2 (Hard) - Maximum sum square sub-matrix of given size
problem: https://www.geeksforgeeks.org/print-maximum-sum-square-sub-matrix-of-given-size/
*/
#include <iostream>
#include <vector>
#include <climits> // Needed for INT_MIN
using namespace std;

void printMaxSquare(vector<vector<int>> matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxSum = INT_MIN;
    int bestRow = 0;
    int bestCol = 0;

    for (int i = 0; i <= rows - k; i++) {
        for (int j = 0; j <= cols - k; j++) {
            int sum = 0;

            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    sum += matrix[i + x][j + y];
                }
            }

            if (sum > maxSum) {
                maxSum = sum;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << "Square with biggest sum is:\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << matrix[bestRow + i][bestCol + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {-1, 8, 6, 8},
        {7, -6, 5, 2},
        {3, 9, -3, 4},
        {2, 4, 8, -1}
    };

    int k = 3;
    printMaxSquare(matrix, k);

    return 0;
}

