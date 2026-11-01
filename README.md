# Student Record Management System

A modular C application designed to manage student records. It allows you to create, modify, delete, search, sort, and print student information using structured file operations.

## 📂 Project Structure

* **main.c**: The core application driver and menu control loop.
* **header.h**: Contains structural definitions, dependencies, and function prototypes.
* **makefile**: Automated compilation script to build the project seamlessly.
* **add_std.c**: Logic for creating and adding new student entries.
* **delete.c**: Functions to securely remove records from the system.
* **modify.c**: Allows editing existing student record fields.
* **sort.c**: Implements sorting routines for student records.
* **print.c**: Handles clear console output formatting for viewing records.
* **save.c**: Commits current record structures back to long-term storage.

## 🛠️ How to Compile and Run

This project includes a `makefile` to simplify compilation. You do not need to run `gcc` on individual files manually.

### 1. Compile the Project
Open your terminal inside this project folder and run:
```bash
make
```
*(This will read your `makefile` and automatically compile all the `.c` files into a single executable).*

### 2. Run the Program
Execute the compiled binary:
```bash
./a.out
```
*(Note: Replace `./main` with whatever target executable name your makefile outputs, such as `./student_record` or `./app`, if it differs).*

### 3. Clean Build Files (Optional)
To delete intermediate object files (`.o`) and reset your directory, run:
```bash
make clean
```

## 👤 Author
* Rajesh G
*
