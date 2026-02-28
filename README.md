# 🧮 Matrix Determinant Calculator

A command-line C++ program that computes the determinant of any square matrix of order N×N.

> Built by [Ukpai Chika Nwakaibeya](https://github.com/chika-io)

---

## Features

- Supports **any N×N matrix** (up to 20×20 and beyond)
- Uses **LU Decomposition** with partial pivoting for numerical stability
- Detects **singular matrices** (determinant = 0) and reports linear dependence
- Clean, interactive CLI with input validation
- Handles both integer and floating-point inputs

---

## How It Works

The program uses **Gaussian Elimination with Partial Pivoting**:

1. For each column, it finds the row with the largest absolute value (pivot) to reduce floating-point errors
2. It swaps rows as needed, tracking sign changes (each swap negates the determinant)
3. It eliminates entries below the pivot to form an upper triangular matrix
4. The determinant is the product of all pivot elements (diagonal of the upper triangular matrix)

**Time Complexity:** O(n³)

---

## Getting Started

### Prerequisites
- A C++ compiler supporting C++17 (e.g., g++, clang++)

### Compile & Run

```bash
# Compile
g++ -std=c++17 -o determinant determinant.cpp

# Run
./determinant
```

---

## Example Usage

```
╔══════════════════════════════════════╗
║   MATRIX DETERMINANT CALCULATOR      ║
║   github.com/chika-io                ║
╚══════════════════════════════════════╝

  Enter matrix order (N for N×N, max 20): 3

  Enter matrix elements row by row:

  Row 1, Col 1: 6
  Row 1, Col 2: 1
  Row 1, Col 3: 1
  ...

  Matrix:
  [     6.0000      1.0000      1.0000 ]
  [     4.0000     -2.0000      5.0000 ]
  [     2.0000      8.0000      7.0000 ]

  ┌─────────────────────────────────┐
  │  Determinant =      -306.000000  │
  └─────────────────────────────────┘

  ✔  The matrix is NON-SINGULAR (invertible).
```

---

## Project Structure

```
determinant-calculator/
│
├── determinant.cpp   # Main application file
└── README.md         # Project documentation
```

---

## Skills Demonstrated

- C++ programming (vectors, functions, templates)
- Numerical methods (LU Decomposition / Gaussian Elimination)
- Linear algebra concepts (determinants, singular matrices, pivoting)
- Input validation and CLI design

---

## License

This project is open source and available under the [MIT License](LICENSE).
