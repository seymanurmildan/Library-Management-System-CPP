#pragma once
#include "Base.h"
#include <string>
#include <iostream>
using namespace std;

class Book :
    public Base
{
private:
    string author;
    bool Isborrow=false;
    string borrowedByUserId = "";
public:
    Book(string _Id,string _name,string _author);
    void setAuthor(string a);
    string getAuthor()const;

    void setBorrow(bool b);
    bool getBorrow()const;

    void setBorrowedByUserId(string uId);
    string getBorrowedByUserId() const;

    void printInfo() const override;
    ~Book();
};

