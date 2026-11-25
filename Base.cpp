#include "Base.h"
#include <string>
#include <iostream>
using namespace std;

Base::Base(string _Id,string _name) {
	Id = _Id;
	name = _name;
}
void Base::setId(string i) {
	Id = i;
}
string Base::getId()const {
	return Id;
}
void Base::setName(string n) {
	name = n;
}
string Base::getName()const {
	return name;
}
Base ::~Base() {

}