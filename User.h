#pragma once
#include "Base.h"

class User : 
    public Base 
{
protected:
    string surname;
    int currentBooks = 0;

public:
    User(string _Id, string _name, string _surname);

    string getSurname() const;
    int getCurrentBooks() const;

    void increaseBooks();
    void decreaseBooks();

    virtual int getMaxLimit() const = 0;
    virtual string getUserType() const = 0;
    virtual ~User();
};