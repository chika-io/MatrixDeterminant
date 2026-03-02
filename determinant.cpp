/*
 * ============================================
 *   Matrix Determinant Calculator
 *   Author : Ukpai Chika Nwakaibeya
 *   GitHub : https://github.com/chika-io
 *   Lang   : C++17
 * ============================================
 *
 * Computes the determinant of any square matrix
 * using LU Decomposition (Gaussian Elimination
 * with partial pivoting) for numerical stability.
 *
 * Supports any N x N matrix (N >= 1).
 *
 * Compile : g++ -std=c++17 -o determinant determinant.cpp
 * Run     : ./determinant
 * ============================================
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

typedef vector<vector<double>> Matrix;

// ─────────────────────────────────────────────
//  HELPERS
// ─────────────────────────────────────────────

void printBanner() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║   MATRIX DETERMINANT CALCULATOR      ║\n";
    cout << "  ║   github.com/chika-io                ║\n";
    cout << "  ╚══════════════════════════════════════╝\n\n";
}

void printMatrix(const Matrix& mat, int n) {
    cout << "\n  Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "  [ ";
        for (int j = 0; j < n; j++) {
            cout << setw(10) << fixed << setprecision(4) << mat[i][j];
            if (j < n - 1) cout << "  ";
        }
        cout << " ]\n";
    }
    cout << "\n";
}

double getValidNumber(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        istringstream ss(line);
        if (ss >> val) {
            string leftover;
            if (!(ss >> leftover)) break;
        }
        cout << "  ⚠  Invalid input. Please enter a number.\n";
    }
    return val;
}

int getValidInt(const string& prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        istringstream ss(line);
        if (ss >> val && val >= minVal && val <= maxVal) {
            string leftover;
            if (!(ss >> leftover)) break;
        }
        cout << "  ⚠  Please enter an integer between "
             << minVal << " and " << maxVal << ".\n";
    }
    return val;
}

// ─────────────────────────────────────────────
//  DETERMINANT — LU Decomposition
//  (Gaussian elimination with partial pivoting)
//
//  Returns the determinant of an n x n matrix.
//  Time complexity: O(n³)
// ─────────────────────────────────────────────

double determinant(Matrix mat, int n) {
    double det = 1.0;
    const double EPS = 1e-12;

    for (int col = 0; col < n; col++) {

        // ── Partial Pivoting: find row with max absolute value in this column
        int pivotRow = col;
        double maxVal = fabs(mat[col][col]);

        for (int row = col + 1; row < n; row++) {
            if (fabs(mat[row][col]) > maxVal) {
                maxVal = fabs(mat[row][col]);
                pivotRow = row;
            }
        }

        // ── Singular matrix check
        if (fabs(mat[pivotRow][col]) < EPS) {
            return 0.0;
        }

        // ── Swap rows if needed (each swap negates the determinant)
        if (pivotRow != col) {
            swap(mat[col], mat[pivotRow]);
            det *= -1.0;
        }

        // ── Eliminate entries below the pivot
        double pivot = mat[col][col];
        det *= pivot;

        for (int row = col + 1; row < n; row++) {
            double factor = mat[row][col] / pivot;
            for (int k = col; k < n; k++) {
                mat[row][k] -= factor * mat[col][k];
            }
        }
    }

    return det;
}

// ─────────────────────────────────────────────
//  DISPLAY RESULT
// ─────────────────────────────────────────────

void printResult(double det) {
    cout << "  ┌─────────────────────────────────┐\n";
    cout << "  │  Determinant = "
         << setw(16) << fixed << setprecision(6) << det
         << "  │\n";
    cout << "  └─────────────────────────────────┘\n\n";

    if (det == 0.0) {
        cout << "  ℹ  The matrix is SINGULAR (det = 0).\n";
        cout << "     This means it has no inverse and its\n";
        cout << "     rows/columns are linearly dependent.\n\n";
    } else {
        cout << "  ✔  The matrix is NON-SINGULAR (invertible).\n\n";
    }
}

// ─────────────────────────────────────────────
//  INPUT MATRIX
// ─────────────────────────────────────────────

Matrix inputMatrix(int n) {
    Matrix mat(n, vector<double>(n));
    cout << "\n  Enter matrix elements row by row:\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string prompt = "  Row " + to_string(i + 1) +
                            ", Col " + to_string(j + 1) + ": ";
            mat[i][j] = getValidNumber(prompt);
        }
        cout << "\n";
    }
    return mat;
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────

int main() {
    printBanner();

    char again = 'y';

    while (tolower(again) == 'y') {

        cout << "  ── New Calculation ──────────────────\n\n";

        int n = getValidInt("  Enter matrix order (N for N×N, max 20): ", 1, 20);

        cout << "\n  Computing determinant of a "
             << n << "×" << n << " matrix.\n";

        Matrix mat = inputMatrix(n);
        printMatrix(mat, n);

        double det = determinant(mat, n);
        printResult(det);

        cout << "  ─────────────────────────────────────\n";
        cout << "  Calculate another determinant? (y/n): ";
        string input;
        getline(cin, input);
        again = input.empty() ? 'n' : input[0];
        cout << "\n";
    }

    cout << "  Thanks for using Determinant Calculator. Goodbye!\n\n";
    return 0;
}
