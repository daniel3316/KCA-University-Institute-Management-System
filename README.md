
# Institute Management System (C++)

A menu-driven Institute Management System developed in C++ as an academic project at KCA University. The project demonstrates object-oriented programming principles and file-based data persistence.

## Overview

The system organizes information related to people, training programmes, equipment inventory, and maintenance records. It uses classes to represent the main entities and text files to save and reload records.

## Features

- **People management:** Models people, trainees, and trainers using classes and inheritance.
- **Training programmes:** Provides functionality for adding and viewing training programmes.
- **Equipment inventory:** Supports adding equipment and viewing inventory records.
- **Maintenance records:** Supports recording maintenance information and viewing maintenance reports.
- **File-based persistence:** Saves and loads records using text files.
- **Input validation:** Validates trainee assessment marks to ensure they fall within the range of 0–100.
- **Menu-driven interaction:** Provides a console-based menu for accessing system operations.

## Object-Oriented Programming Concepts

The project demonstrates:

- **Classes and objects:** Represents institute entities using classes.
- **Encapsulation:** Uses access specifiers and getter/setter methods to manage data access.
- **Inheritance:** Derives `Trainee` and `Trainer` from the `Person` base class.
- **Polymorphism:** Uses virtual methods for entity-specific behaviour.
- **Constructors and destructors:** Initializes objects and supports appropriate object cleanup.
- **Exception handling:** Uses exceptions to handle validation errors.

## Technologies Used

- C++
- Standard Template Library (STL)
- File input/output (`fstream`)
- Console-based interface
- Text-file data storage

## Project Structure

```text
KCA_University_System/
├── main.cpp
├── users.txt
├── programmes.txt
├── equipment.txt
├── maintenance.txt
├── README.md
└── .gitignore
```

## Getting Started

### Prerequisites

- A C++ compiler, such as GCC (`g++`).
- A terminal or C++ development environment.

### Compile

Open a terminal in the project directory and run:

```bash
g++ -std=c++11 main.cpp -o institute_management
```

### Run

On Windows PowerShell:

```powershell
.\institute_management.exe
```

On Linux or macOS:

```bash
./institute_management
```

Run the program from the project directory so that the text data files can be found.

## Data Files

The program uses the following text files for storing records:

- `users.txt`
- `programmes.txt`
- `equipment.txt`
- `maintenance.txt`

The program's save and load functions handle these files.

**Note:** The text files included in the repository are sample project data, not a production database.

## Learning Outcomes

This project provided practical experience with object-oriented design, class relationships, file handling, input validation, exception handling, and organizing a menu-driven C++ application.

## Author

Daniel Deng

Applied Computing Student, KCA University

## Disclaimer

This project was developed for academic and learning purposes. It is not intended to be used as a production-ready institute management system.
