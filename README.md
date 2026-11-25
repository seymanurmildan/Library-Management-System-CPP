# Library-Management-System-CPP
Object-Oriented C++ Console Application for managing library books, users (Students &amp; Academics), and borrowing/returning operations.
## Overview & Features

This project demonstrates modular C++ software design by enforcing university library rules across distinct user roles:

* **Book Operations:** Add books with unique IDs, list all inventory with availability status, search by exact title or author, and delete available books safely.
* **User Operations:** Register **Students** (borrowing limit: `3`) and **Academics** (borrowing limit: `5`), view user records, and remove users with zero active loans.
* **Borrow & Return Engine:** Validates user existence, role limits, and book availability immediately upon ID entry, while tracking active loans and preventing invalid returns or deletions.
* **Architecture & Memory:** Built with C++11/17 (`std::vector`, `std::string`) using a multi-level inheritance hierarchy (`Base` -> `Book` / `User` -> `Student` / `Academic`), runtime polymorphism (`virtual` methods), encapsulation, and destructor cleanup (`~Library()`).

---

## System Architecture & Diagrams

The `Base` and `User` abstract classes encapsulate shared attributes (`Id`, `name`, `surname`) and define virtual interfaces (`getMaxLimit()`, `getUserType()`, `printInfo()`). Derived classes (`Student` and `Academic`) override these rules polymorphically, while `Library` coordinates all object collections and business logic.
### Sample Console Output

```text
----------MENU----------
1-)Add book
2-)Book list
3-)Search book
4-)Remove book
5-)Add user
6-)User list
7-)Delete user
8-)Borrow book
9-)Return book
10-)Borrow list
0-)Exit
Choice: 1
Enter Book ID: 101
Enter Book Title: Clean Code
Enter Author: Robert C. Martin
Success: Book 'Clean Code' added.
```
