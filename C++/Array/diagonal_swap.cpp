#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int matrix[n][n];

    // Input matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Interchange diagonals
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][i];               // Primary diagonal element
        matrix[i][i] = matrix[i][n - 1 - i];  // Replace with secondary diagonal
        matrix[i][n - 1 - i] = temp;           // Replace secondary with primary
    }

    // Output modified matrix
    cout << "Matrix after interchanging diagonals:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
