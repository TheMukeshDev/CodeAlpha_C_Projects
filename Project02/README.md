# Project02 — Matrix Operations

File: `matrixcode.c`

Overview
- Implements basic matrix operations for integer matrices using fixed-size arrays (max 10×10):
  - Matrix addition
  - Matrix multiplication
  - Matrix transpose
- Demonstrates: modular functions, 2D arrays, nested loops, and input/output.

Key functions
- `input_2matrix(int m1[][10], int m2[][10], int r1, int c1, int r2, int c2, int i, int j)`
  - Prompts the user to enter values for matrix `m1` and `m2` based on the provided row/column sizes.

- `matrix_addition(...)`
  - Verifies dimensions match, reads the matrices using `input_2matrix`, computes the element-wise sum, and prints the result.

- `matrix_mult(...)`
  - Verifies multiplication compatibility (`c1 == r2`), reads matrices, computes matrix multiplication using a triple loop, and prints the product.

- `matrix_transpose(...)`
  - Reads a single matrix and prints its transpose (rows ↔ columns).

Main program flow
- The `main()` function reads the size of the first matrix and asks which operation the user wants.
- For addition and multiplication, it asks for the second matrix size then calls the chosen function.

Build & Run (Windows PowerShell)
```powershell
gcc -Wall -Wextra -std=c11 "Project02\matrixcode.c" -o "Project02\matrixcode.exe"
& "Project02\matrixcode.exe"
```
