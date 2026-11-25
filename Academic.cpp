#include "Academic.h"
#include <string>
#include <iostream>
using namespace std;


Academic::Academic(string _Id, string _name, string _surname):User(_Id,_name,_surname) {
	
}
int Academic::getMaxLimit() const {
    return number;
}

string Academic::getUserType() const {
    return "Academic";
}

void Academic::printInfo() const {
    cout << "[Academic] ID: " << Id
        << " | Name: " << name << " " << surname
        << " | Borrowed Books: " << currentBooks << "/" << number << endl;
}
Academic::~Academic() {

}