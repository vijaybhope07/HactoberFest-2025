// The Knight's Tour Problem:
//
// Given a chessboard of size N x N, place a knight on any starting square
// (usually (0,0)). The knight must visit every square on the board exactly once
// following the rules of chess (a knight moves in an "L" shape — 2 squares in
// one direction and then 1 square perpendicular).
//
// The goal is to find one possible sequence of moves such that the knight
// visits all N*N squares exactly once.
//
// Use backtracking to explore all possible moves of the knight from each
// position. If a move leads to a dead end (no further valid moves), backtrack
// and try another path.
//
// Output the board configuration showing the order in which the knight visits
// each cell.

// C++ program to solve Knight's Tour problem using Backtracking
#include <iomanip>
#include <iostream>
using namespace std;

#define N 8  // Board size (8x8 chessboard)

// Utility function to print the chessboard
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) cout << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
    cout << endl;
}

// Check if (x, y) is a valid move
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* Recursive utility function to solve Knight's Tour problem */
bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],
                 int yMove[N]) {
    // Base case: if all squares are visited
    if (movei == N * N) return true;

    // Try all next moves from the current coordinate x, y
    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
                return true;
            else
                // Backtrack
                sol[next_x][next_y] = -1;
        }
    }

    return false;
}

void solveKT() {
    int sol[N][N];

    // Initialization of solution matrix
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) sol[x][y] = -1;

    // xMove[] and yMove[] define next moves for the knight
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Start from (0, 0)
    sol[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove))
        cout << "Solution does not exist" << endl;
    else
        printSolution(sol);
}

int main() {
    cout << "Knight's Tour Solution:\n";
    solveKT();
    return 0;
}