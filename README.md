# C++ Module 00: A Gentle Introduction

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This project is the first module in the C++ series of the 42 core curriculum. Its primary goal is to introduce fundamental concepts of C++ and Object-Oriented Programming (OOP), highlighting the key differences and advantages compared to the C programming language.

This module covers essential building blocks necessary for subsequent C++ projects, focusing on classes, encapsulation, basic input/output handling, and the compilation process in C++.

## Concepts Learned and Applied

This module provides practical experience with several core C++ features:

*   **Namespaces:** Understanding how namespaces (`std` namespace in particular) prevent naming conflicts.
*   **Classes and Objects:** Defining blueprints (classes like `PhoneBook`, `Contact`, `Account`) for creating objects, encapsulating data (member variables) and behavior (member functions).
*   **Member Functions:** Implementing functions that operate on the data within an object.
*   **Access Specifiers:** Using `public` and `private` to control access to class members, enforcing encapsulation.
*   **Input/Output Streams:** Using `iostream` (`std::cin`, `std::cout`) for handling console input and output, including formatting (`iomanip`).
*   **Initialization Lists:** Initializing member variables in constructors using the preferred C++ way.
*   **Static Members:** Using `static` variables and functions within a class (`Account`) to manage data and behavior shared across all instances of the class.
*   **Const Correctness:** Using the `const` keyword to specify methods that do not modify the object's state and to return constant references.
*   **Header Files (.h/.hpp) and Source Files (.cpp):** Separating class declarations (interface) from their implementations.
*   **Basic String Manipulation:** Working with the `std::string` class, including reading input (`std::getline`), checking length, and extracting substrings (`substr`).
*   **Command-Line Arguments:** Handling `argc` and `argv` in C++.
*   **Basic Type Casting:** Using `static_cast`.

## Project Exercises

This module consists of three exercises:

### Exercise 00: Megaphone

*   **Task:** Create a program named `megaphone` that converts command-line arguments to uppercase and prints them without spaces in between. If no arguments are provided, it should print `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
*   **Implementation:** Uses `iostream` for output and `cctype` (`std::toupper`) for character conversion. Iterates through `argv` to process arguments.
*   **Files:** `megaphone.cpp`, `Makefile`

### Exercise 01: My Awesome PhoneBook

*   **Task:** Implement a simple interactive phonebook program. The program should accept three commands:
    *   `ADD`: Prompts the user for contact information (first name, last name, nickname, phone number, darkest secret) and saves a new contact. The phonebook can store a maximum of 8 contacts. If the phonebook is full, the oldest contact is replaced. Empty fields are not allowed.
    *   `SEARCH`: Displays a list of saved contacts (index, first name, last name, nickname), truncating fields wider than 10 characters with a dot. It then prompts the user for the index of the contact to display and prints all its details.
    *   `EXIT`: Quits the program. Contacts are lost upon exit.
*   **Implementation:**
    *   Uses two classes: `PhoneBook` and `Contact`.
    *   `Contact` stores the information for a single contact and provides methods to set and get the data.
    *   `PhoneBook` manages an array of 8 `Contact` objects. It handles the user interaction loop, adding contacts (using a static index for circular replacement), and performing searches.
    *   Input is handled carefully using `std::getline` and `std::ws` to manage whitespace. `std::stringstream` is used for validating the index input during search.
    *   Output formatting is done using `iomanip` (`std::setw`, `std::right`).
*   **Files:** `main.cpp`, `PhoneBook.h`, `PhoneBook.cpp`, `Contact.h`, `Contact.cpp`, `Makefile`

### Exercise 02: The Job of Your Dreams

*   **Task:** Given a header file (`Account.hpp`) defining the interface for an `Account` class and a test file (`tests.cpp`), implement the `Account.cpp` file. The class simulates bank accounts, tracking individual balances, deposits, and withdrawals, as well as class-wide totals (total number of accounts, total balance, total deposits/withdrawals).
*   **Implementation:**
    *   The core challenge lies in correctly implementing both instance members (like `_amount`, `_nbDeposits`) and static members (`_nbAccounts`, `_totalAmount`, etc.).
    *   Constructors initialize accounts and update static totals.
    *   Destructors update static totals when accounts are implicitly destroyed (e.g., when the `vector` in `tests.cpp` goes out of scope).
    *   Member functions (`makeDeposit`, `makeWithdrawal`, `displayStatus`) perform actions on individual accounts and update totals accordingly.
    *   Static functions (`getNbAccounts`, `displayAccountsInfos`) provide access to class-wide information.
    *   A private static helper function (`_displayTimestamp`) is required to print timestamps in the specific format `[YYYYMMDD_HHMMSS]`. This involves using the `<ctime>` library and `iomanip` for formatting.
    *   Careful attention must be paid to match the exact output format shown in the example logs, as the evaluation often relies on `diff`.
    *   **Note:** This exercise specifically requires compilation with the `-std=c++98` flag in order to be compatible with the deprecated `mem_fun_ref` function.
*   **Files:** `Account.hpp` (provided), `tests.cpp` (provided), `Account.cpp` (to be implemented), `Makefile`

## Building the Project

Each exercise is located in its respective directory (e.g., `ex00/`, `ex01/`, `ex02/`). Navigate into the desired directory and use the provided `Makefile`.

1.  **Navigate to the exercise directory:**
    ```bash
    cd ex00  # or ex01, ex02
    ```
2.  **Compile the project:**
    ```bash
    make
    ```
    This will compile the source files using `c++` with the flags `-Wall -Wextra -Werror` and the appropriate C++ standard (`-std=c++17` for ex00/ex01, `-std=c++98` for ex02) and create the executable (`megaphone`, `phonebook`, or `job`).

3.  **Other make commands:**
    *   `make clean`: Removes the object files (`.o`).
    *   `make fclean`: Removes object files and the executable.
    *   `make re`: Runs `fclean` followed by `make`.

## Usage

### Megaphone (ex00)

```bash
# Run with arguments
./megaphone HELLO world HOW are YOU?
# Expected Output: HELLOWORLDHOWAREYOU?

# Run without arguments
./megaphone
# Expected Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### PhoneBook (ex01)

```bash
./phonebook
```
The program will then prompt you to enter commands (`ADD`, `SEARCH`, `EXIT`). Follow the on-screen prompts.

### The Job (ex02)

```bash
./job
```
This will run the pre-defined tests from `tests.cpp`, creating accounts, making deposits/withdrawals, and printing logs to the console. Compare the output against the expected log file provided by the subject.
