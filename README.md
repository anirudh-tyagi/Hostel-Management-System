# Hostel Accommodation System

## Description
This is a simple C++ program for managing hostel accommodations. It allows students to reserve beds in a hostel, updates the availability of beds in a text file, and stores student details in a separate file.

## Features
- Allows students to reserve a bed in the hostel.
- Stores hostel details including name, rent, and available beds.
- Updates the number of available beds after reservation.
- Stores student details (name, roll number, and address) in a file.
- Ensures file handling with error checking.

## Files Used
- `Hostel.txt` → Stores hostel information.
- `Student.txt` → Stores student reservation details.

## Requirements
- C++ compiler (GCC, Clang, or MSVC)
- Permission to create and modify files in the working directory

## How to Compile and Run
1. Open a terminal or command prompt.
2. Navigate to the directory where the source code is located.
3. Compile the code using the following command:
   ```sh
   g++ hostel_reservation.cpp -o hostel
   ```
4. Run the program:
   ```sh
   ./hostel  # On Linux/Mac
   hostel.exe  # On Windows
   ```

## Troubleshooting
- If you see `Error: Unable to open file for reading/writing`, check:
  - That you have the correct permissions.
  - The file is not open elsewhere.
  - The working directory is correct.
- Run the program as administrator if necessary.

## Future Enhancements
- Add a graphical user interface (GUI).
- Implement a database instead of text files.
- Allow multiple hostel options.

## Author
- Developed by Anirudh Tyagi & Ayush Jasani
