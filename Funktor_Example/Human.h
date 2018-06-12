#pragma once
#include"Library.h"

class Human {
	string name;
	string sname;
	int age;
public:
	Human(string name, string sname, int age) {
		this->name = name;
		this->sname = sname;
		this->age = age;
	}
	string getName()const { return name; }
	string getSname() const{ return sname; }
	int getAge()const { return age; }
};