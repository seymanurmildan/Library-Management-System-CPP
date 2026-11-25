#include "User.h"
#include <string>
#include <iostream>
using namespace std;

User::User(string _Id, string _name, string _surname) : Base(_Id, _name) {
    surname = _surname;
}

string User::getSurname() const {
    return surname;
}

int User::getCurrentBooks() const {
    return currentBooks;
}

void User::increaseBooks() {
    currentBooks++;
}

void User::decreaseBooks() {
    if (currentBooks > 0) {
        currentBooks--;
    }
}

User::~User() {
}