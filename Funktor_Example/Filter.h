#pragma once
#include"Human.h"

class Filter {
	string key;
	string svalue;
	int ivalue;
public:
	Filter(string key, string svalue) {
		this->key = key;
		this->svalue = svalue;
	}
	Filter(string key, int ivalue) {
		this->key = key;
		this->ivalue = ivalue;
	}

	bool operator()(Human h) {
		if (this->key == "name") {
			if (svalue == h.getName())
				return true;
		}
		else if (this->key == "sname") {
			if (svalue == h.getSname())
				return true;
		}
		else if (this->key == "age") {
			if (ivalue == h.getAge())
				return true;
		}
		return false;
	}
};