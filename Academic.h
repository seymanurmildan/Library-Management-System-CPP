#pragma once
#include "User.h"
#include <string>
#include <iostream>
using namespace std;

class Academic :
    public User
{
private:
   const int number = 5;
 public:
        Academic(string _Id, string _name, string _surname);
        int getMaxLimit() const override;
        string getUserType() const override;
        void printInfo() const override;
        ~Academic();
};

