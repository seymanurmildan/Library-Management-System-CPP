#pragma once
#include <iostream>
#include <string>
#include <vector>    
#include "Book.h"     
#include "Student.h"  
#include "User.h"
#include "Academic.h"
using namespace std;

class Library
{
private:
	vector <Book*> books;
	vector <User*> users;

public:
    
    Book* findBookById(string bookId) const;
    User* findUserById(string userId) const;

    void addBook(Book* newBook);
    void removeBook(string bookId);
    void addUser(User* newUserr);
    void deleteUser(string userId);
    
    void searchBook(string keyword) const;
    void listAllBooks() const;
    void borrowList() const;
    void listUsers() const;

   
    void borrowBook(string userId, string bookId);
    void returnBook(string userId, string bookId);

    ~Library();
};

