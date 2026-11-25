#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

Book::Book(string _Id, string _name, string _author) :Base(_Id, _name) {
	author = _author;
}
void Book::setAuthor(string a) {
	author = a;
}
string Book::getAuthor()const {
	return author;
}
void Book::setBorrow(bool b) {
	Isborrow = b;
}
bool Book::getBorrow()const {
	return Isborrow;
}
void Book::setBorrowedByUserId(string uId) {
    borrowedByUserId = uId;
}

string Book::getBorrowedByUserId() const {
    return borrowedByUserId;
}

void Book::printInfo() const {
    cout << "[Book] ID: " << Id
        << " | Title: " << name
        << " | Author: " << author
        << " | Status: ";

    if (Isborrow == true) {
        cout << "Borrowed (User ID: " + borrowedByUserId + ")";
    }
    else {
        cout << "Available";
    } 
    cout << endl;
}
Book::~Book() {

}