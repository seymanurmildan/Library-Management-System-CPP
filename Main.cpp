#include "Library.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	Library lib;
	int choice;
    string bookId, bookName, authorName, keyword;
    string userId, userName, userSurname;
    int userType;

	do {
		cout << "-----------MENU------------" << endl <<
			"1-)Add book " << endl <<
			"2-)Book list" << endl <<
			"3-)Search book" << endl <<
			"4-)Remove book" << endl <<
			"5-)Add user" << endl <<
			"6-)User list" << endl <<
		    "7-)Delete user" << endl<<
			"8-)Borrow book" << endl <<
			"9-)Return book" << endl <<
			"10-)Borrow list" << endl <<
			"0-)Exit"<<endl<<
			"Choice:";

		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input! Please enter a number." << endl;
			continue;
		}

		switch (choice) {
        case 1: {
            string id, title, author;
            cout << "Enter Book ID: ";
            cin >> id;

            if (lib.findBookById(id) != nullptr) {
                cout << "Error: A book with ID '" << id << "' already exists!" << endl;
                break; 
            }

           
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);

            lib.addBook(new Book(id, title, author));
            break;
        }
        case 2:
            lib.listAllBooks();
            break;

        case 3:
            cin.ignore();
            cout << "Enter book title or author name to search: ";
            getline(cin, keyword);
            lib.searchBook(keyword);
            break;

        case 4:
            cout << "Enter the book Id to remove: ";
            cin >> bookId;
            lib.removeBook(bookId);
            break;

        case 5:
            cout << "Select user type (1- Student, 2- Academic): ";
            cin >> userType;
            if (userType != 1 && userType != 2) {
                cout << "Invalid user type!" << endl;
                break;
            }
            cout << "Enter user Id: ";
            cin >> userId;
            if (lib.findUserById(userId) != nullptr) {
                cout << "Error: A user with ID '" << userId << "' already exists!" << endl;
                break;
            }
            cin.ignore();
            cout << "Enter first name: ";
            getline(cin, userName);
            cout << "Enter surname: ";
            getline(cin, userSurname);

            if (userType == 1) {
                lib.addUser(new Student(userId, userName, userSurname));
            }
            else {
                lib.addUser(new Academic(userId, userName, userSurname));
            }
            break;

        case 6:
            lib.listUsers();
            break;

        case 7:
            cout << "Enter the user Id to delete: ";
            cin >> userId;
            lib.deleteUser(userId);
            break;

        case 8:
            cout << "Enter user Id: ";
            cin >> userId;
            if (lib.findUserById(userId) == nullptr) {
                cout << "Error: User with ID '" << userId << "' not found!" << endl;
                break;
            }
            cout << "Enter book Id: ";
            cin >> bookId;
            if (lib.findBookById(bookId) == nullptr) {
                cout << "Error: Book with ID '" << bookId << "' not found!" << endl;
                break;
            }
            lib.borrowBook(userId, bookId);
            break;

        case 9:
            cout << "Enter user Id: ";
            cin >> userId;
            cout << "Enter book Id: ";
            cin >> bookId;
            lib.returnBook(userId, bookId);
            break;

        case 10:
            lib.borrowList();
            break;

        case 0:
            cout << "Exiting program" << endl;
            break;

        default:
            cout << "Invalid choice! Please select between 0 and 10." << endl;
            break;
		}


	} while (choice != 0);

	return 0;
}