#pragma once
#include "User.h"
#include <string>
#include <iostream>
using namespace std;

class Student :
    public User
{
private:
    const int number = 3;

public:
    Student(string _Id, string _name,string _surname);
    int getMaxLimit() const override;
    string getUserType() const override;
    void printInfo() const override;
    ~Student();
};

