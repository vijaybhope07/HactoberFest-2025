// C++ program to interchange diagonals of a square matrix
// Swaps elements of main diagonal with secondary diagonal
// Time Complexity: O(n), Space Complexity: O(n^2)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // Input validation
    if (cin.fail() || n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    // Use vector for dynamic 2D array (better than VLA)
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Interchange diagonals
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][i];               // Primary diagonal element
        matrix[i][i] = matrix[i][n - 1 - i];   // Replace with secondary diagonal
        matrix[i][n - 1 - i] = temp;           // Replace secondary with primary
    }

    // Output modified matrix
    cout << "Matrix after interchanging diagonals:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
