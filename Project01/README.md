# Project01 — Basic Calculator

File: `basic_cal.c`

Overview
- A simple command-line calculator that performs addition, subtraction, multiplication, and division on two numbers (supports floating-point).
- Demonstrates: standard I/O (`printf`/`scanf` with `%lf`), `switch` statement, basic error handling (division by zero).

How it works (code walkthrough)
-- `main()` prompts the user for two numbers (floating-point) and an operator character (`+`, `-`, `*`, `/`).
-- A `switch` statement selects the operation and prints the result.
-- Division is handled carefully: the program checks for division-by-zero using a small epsilon and prints an error if detected; otherwise it prints a floating-point result.

Build & Run (Windows PowerShell)
```powershell
gcc -Wall -Wextra -std=c11 "Project01\basic_cal.c" -o "Project01\basic_cal.exe"
& "Project01\basic_cal.exe"
```

Sample session
```
Basic calculator (Addition, Subtraction, Multiplication & Division)
Enter 1st Number: 10.5
Enter 2nd Number: 2
+ for addition
- for subtraction
* for multiplication
/ for division
Enter Operator sign : /
Division of 10.5 / 2 = 5.25
```

