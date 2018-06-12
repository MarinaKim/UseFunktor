#include"Human.h"
#include"Filter.h"
#include "SortByKey.h"
#include "FindByKey.h"
void print(Human h) {
	cout << h.getName() << "\t" << h.getSname() << "\t" << h.getAge() << endl;
}
int main() {

	vector<Human>vh;
	vh.push_back(Human("Asan", "Asan", 28));
	vh.push_back(Human("Ivan", "Ivanov", 25));
	vh.push_back(Human("Aman", "Ahmetov", 31));
	vh.push_back(Human("Roman", "Petrov", 30));
	vh.push_back(Human("Esen", "Ahmetov", 18));
	for_each(vh.begin(), vh.end(), print);
	cout << "----------------------------------------------------" << endl;
	int n;
	cout << "num: ";
	cin >> n;
	switch (n) {
		//filter example
	case 1: {
		auto itr = vh.erase(remove_if(vh.begin(), vh.end(), Filter("name", "Asan")), vh.end());
		for_each(vh.begin(), vh.end(), print);
	}break;

		//filter with menu
	case 2: {
		int key;
		cout << "Enter the key:";
		cout << "1. by name" << endl;
		cout << "2. by sname" << endl;
		cout << "3. by age" << endl;
		cin >> key;

		switch (key)
		{
		case 1: {
			string name;
			cout << "enter the name:";
			cin >> name;
			auto itr = vh.erase(remove_if(vh.begin(), vh.end(), Filter("name", name)), vh.end());
			for_each(vh.begin(), vh.end(), print);
		}break;

		case 2: {
			string sname;
			cout << "enter the sname:";
			cin >> sname;
			auto itr = vh.erase(remove_if(vh.begin(), vh.end(), Filter("sname", sname)), vh.end());
			for_each(vh.begin(), vh.end(), print);
		}break;

		case 3: {
			int age;
			cout << "enter the age:";
			cin >> age;
			auto itr = vh.erase(remove_if(vh.begin(), vh.end(), Filter("age", age)), vh.end());
			for_each(vh.begin(), vh.end(), print);
		}break;
		}

	}break;

		//sort by key example
	case 3: {
		sort(vh.begin(), vh.end(), SortByKey("sname"));
		for_each(vh.begin(), vh.end(), print);
	}break;
		//find_if
	case 4: {
		auto itr = find_if(vh.begin(), vh.end(), FindByName("Ivan"));
		if (itr != vh.end())
			cout << itr->getName()<<"\t" << itr->getSname()<<"\t"<<itr->getAge() << endl;
	}break;
	}
	system("pause");
	return 0;
}