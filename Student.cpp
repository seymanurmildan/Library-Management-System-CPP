#include "Student.h"
#include "User.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(string _Id, string _name, string _surname):User(_Id,_name,_surname){

}
int Student::getMaxLimit() const {
    return number;
}

string Student::getUserType() const {
    return "Student";
}

void Student::printInfo() const {
    cout << "[Student] ID: " << Id
        << " | Name: " << name << " " << surname
        << " | Borrowed Books: " << currentBooks << "/" << number << endl;
}
Student::~Student() {

}