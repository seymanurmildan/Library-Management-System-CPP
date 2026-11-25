#pragma once
#include <string>
#include <iostream>
using namespace std;

class Base
{
protected:
	string Id;
	string name;

public:
	Base(string _Id, string _name);

	void setId(string i);
	string getId()const;

	void setName(string n);
	string getName()const;

	virtual void printInfo() const = 0;
	virtual ~Base();
};

