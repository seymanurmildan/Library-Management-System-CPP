#include "Library.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Book* Library::findBookById(string bookId) const {
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getId() == bookId) {
            return books[i];
        }
    }
    return nullptr;
}

User* Library::findUserById(string userId) const {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getId() == userId) {
            return users[i];
        }
    }
    return nullptr;
}

void Library::addBook(Book* newBook) {
    if (findBookById(newBook->getId()) != nullptr) {
        cout << "Error: A book with ID '" << newBook->getId() << "' already exists!" << endl;
        delete newBook;
        return;
    }
    books.push_back(newBook);
    cout << "Success: Book '" << newBook->getName() << "' added." << endl;
}

void Library::listAllBooks() const {
    if (books.size() == 0) {
        cout << "No books registered in the library." << endl;
        return;
    }

    cout << "\n--- BOOK LIST ---" << endl;
    for (int i = 0; i < books.size(); i++) {
        books[i]->printInfo();
    }
}

void Library::searchBook(string keyword) const {
    bool found = false;
    cout << "\n--- SEARCH RESULTS ---" << endl;
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getName() == keyword || books[i]->getAuthor() == keyword) {
            books[i]->printInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No matching books found for '" << keyword << "'." << endl;
    }
}

void Library::removeBook(string bookId) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getId() == bookId) {
            if (books[i]->getBorrow()) {
                cout << "Error: Cannot remove a book that is currently borrowed!" << endl;
                return;
            }
            delete books[i];

            for (int j = i; j < books.size() - 1; j++) {
                books[j] = books[j + 1];
            }

            books.pop_back();

            cout << "Success: Book removed from the system." << endl;
            return;
        }
    }
    cout << "Error: Book with ID '" << bookId << "' not found!" << endl;
}

void Library::addUser(User* newUser) {
    if (findUserById(newUser->getId()) != nullptr) {
        cout << "Error: A user with ID '" << newUser->getId() << "' already exists!" << endl;
        delete newUser;
        return;
    }
    users.push_back(newUser);
    cout << "Success: " << newUser->getUserType() << " '" << newUser->getName() << " " << newUser->getSurname() << "' added." << endl;
}

void Library::listUsers() const {
    if (users.empty()) {
        cout << "No users registered in the library." << endl;
        return;
    }
    cout << "\n--- USER LIST ---" << endl;
    for (int i = 0; i < users.size(); i++) {
        users[i]->printInfo();
    }
}

void Library::deleteUser(string userId) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getId() == userId) {
            if (users[i]->getCurrentBooks() > 0) {
                cout << "Error: User still has borrowed books. Return them first!" << endl;
                return;
            }
            delete users[i];

            for (int j = i; j < users.size() - 1; j++) {
                users[j] = users[j + 1];
            }

            users.pop_back();

            cout << "Success: User deleted." << endl;
            return;
        }
    }
    cout << "Error: User with ID '" << userId << "' not found!" << endl;
}

void Library::borrowBook(string userId, string bookId) {
    User* user = findUserById(userId);
    if (user == nullptr) {
        cout << "Error: User not found!" << endl;
        return;
    }

    Book* book = findBookById(bookId);
    if (book == nullptr) {
        cout << "Error: Book not found!" << endl;
        return;
    }

    if (book->getBorrow()) {
        cout << "Error: Book is already borrowed by another user!" << endl;
        return;
    }

    if (user->getCurrentBooks() >= user->getMaxLimit()) {
        cout << "Error: " << user->getUserType() << " borrow limit (" << user->getMaxLimit() << ") reached!" << endl;
        return;
    }

    book->setBorrow(true);
    book->setBorrowedByUserId(userId);
    user->increaseBooks();
    cout << "Success: '" << book->getName() << "' borrowed by " << user->getName() << user->getSurname() << " ." << endl;
}

void Library::returnBook(string userId, string bookId) {
    User* user = findUserById(userId);
    if (user == nullptr) {
        cout << "Error: User not found!" << endl;
        return;
    }

    Book* book = findBookById(bookId);
    if (book == nullptr) {
        cout << "Error: Book not found!" << endl;
        return;
    }

    if (!book->getBorrow()) {
        cout << "Error: This book is not currently borrowed!" << endl;
        return;
    }

    if (book->getBorrowedByUserId() != userId) {
        cout << "Error: This book was borrowed by another user (ID: " << book->getBorrowedByUserId() << ")!" << endl;
        return;
    }

    book->setBorrow(false);
    book->setBorrowedByUserId("");
    user->decreaseBooks();
    cout << "Success: '" << book->getName() << "' returned by " << user->getName() << "." << endl;
}

void Library::borrowList() const {
    bool hasBorrowed = false;
    cout << "\n--- ACTIVE BORROW LIST ---" << endl;
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getBorrow()) {
            User* holder = findUserById(books[i]->getBorrowedByUserId());
            cout << "Book ID: " << books[i]->getId()
                << " | Title: " << books[i]->getName()
                << " | Borrowed By: ";
            if (holder != nullptr) {
                cout << holder->getName() << " " << holder->getSurname()
                    << " (ID: " << holder->getId() << ", " << holder->getUserType() << ")";
            }
            else {
                cout << "User ID: " << books[i]->getBorrowedByUserId();
            }
            cout << endl;
            hasBorrowed = true;
        }
    }
    if (!hasBorrowed) {
        cout << "No active borrow records found." << endl;
    }
}

Library::~Library() {
    for (int i = 0; i < books.size(); i++) {
        delete books[i];
    }
    books.clear();

    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
    users.clear();
}