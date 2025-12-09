#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num) {

    // Check row
    for (int i = 0; i < 9; i++)
        if (grid[row][i] == num)
            return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[9][9], int row, int col) {

    if (row == 8 && col == 9)
        return true;

    if (col == 9) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0;
    }

    return false;
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {

    int grid[9][9];

    cout << "Enter Sudoku puzzle (use 0 for empty cells):\n";

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    if (solveSudoku(grid, 0, 0)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
