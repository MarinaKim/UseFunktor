#pragma once
#include"Library.h"
#include"Human.h"
class FindByName {
	string name;
public:
	FindByName(string name) {
		this->name = name;
	}

	bool operator()(const Human& h) {
		return (name == h.getName());
	}
};