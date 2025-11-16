# Project03 — Student Management

File: `student_mangement.c`

Overview
- Small CLI student management program that stores student records in a plain-text CSV file (`students.txt`).
- Features: list, add, remove, save. On startup the program loads entries from `students.txt` and merges them into the in-memory list.

Behavior & important notes
- On startup the program calls `load_students()` which reads `students.txt` and merges any records that are not already present in memory. Records with a `student_id` already present in memory are skipped (no duplicate IDs are added).
- The program uses `scanf`/`printf` for interactive input (no `fgets`/`fputs`) and writes the data file in a simple CSV format.
- Data file used: `students.txt` (located in the same folder as the program).

CSV schema (one record per line)
- Format used when saving and expected when loading:
  `id,name,qualification,mark0,mark1,mark2,mark3,mark4,percentage,phone,address`
- Example line:
  `101,John Doe,BSc,75.0,82.5,68.0,90.0,71.5,77.4,555-1234,123 Main St`

Build (Windows PowerShell)
```powershell
cd "Project03"
gcc -Wall -Wextra -std=c11 "student_mangements.c" -o "student_mangements.exe"
```

Run (PowerShell)
```powershell
.\student_mangements.exe
```

Usage notes
- When the program starts it will print a startup banner and then load entries from `students.txt`. If the same `student_id` exists both in memory (e.g., previously added during that execution) and in the file, the file entry will be skipped to avoid duplicates.
- Important: the file loader (`load_students`) reads fields using comma-separated scansets (so names with spaces are supported in the file). However, the interactive `add_student()` uses `scanf("%s")` for `name` and `qualification` which stops at whitespace — interactive multi-word names are not supported unless you change the code to use a scanset or `fgets`.
- The program only writes changes when you choose the "Save and exit" menu option.

Limitations & suggestions
- Current implementation uses fixed-size buffers; fields longer than their buffers will be truncated.
- For robustness against commas/newlines in fields and multi-word interactive input, consider switching to a quoted-CSV read/write or using `fgets` + explicit parsing for interactive input.

Where to look in the code
- `load_students()` — reads and merges records from `students.txt` at startup
- `add_student()` — interactively adds a student (checks for duplicate `student_id` before adding)
- `remove_student_by_id()` — removes a student by ID
- `save_students()` — writes the current in-memory list to `students.txt`

Example: sample `students.txt` and a short session

Sample `students.txt` (two lines):
```
101,John Doe,BSc,75.0,82.5,68.0,90.0,71.5,77.4,555-1234,123 Main St
102,Jane Smith,BEng,88.0,79.5,91.0,85.0,90.0,86.7,555-5678,456 Oak Ave
```

Example session (PowerShell):
```
> .\student_mangements.exe
Student Management System
Loaded 2 new student(s) from file. Total in memory: 2

Menu:
  1) List students
  2) Add single student
  3) Remove student by ID
  4) Save and exit
  5) Exit without saving
Choose option: 1

Student 1:
  ID: 101
  Name: John Doe
  Qualification: BSc
  Marks: 75.0, 82.5, 68.0, 90.0, 71.5
  Percentage: 77.40
  Phone: 555-1234
  Address: 123 Main St

Student 2:
  ID: 102
  Name: Jane Smith
  Qualification: BEng
  Marks: 88.0, 79.5, 91.0, 85.0, 90.0
  Percentage: 86.70
  Phone: 555-5678
  Address: 456 Oak Ave

Choose option: 2
Enter student ID: 101
Student ID 101 already exists — not adding duplicate.

Choose option: 4
Data saved. Exiting.
```

