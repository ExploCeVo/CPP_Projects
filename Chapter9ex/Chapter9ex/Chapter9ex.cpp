/*
Exercises from Chapter 9
Programming Principles and Practice
Chapter9ex.cpp
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// exercise 2
// Implement a name pairs class (name,age)
// name is a string, age is a double
//use vectors
class name_pairs {
public:
	class Invalid {};

	name_pairs(vector<string> nn, vector<double> aa);

	name_pairs();

	vector<string> name_list() { return names; }
	vector<double> age_list() { return ages; }

//	void read_names(name_pairs np);
//	void read_ages();

	vector<string> names;
	vector<double> ages;
};

name_pairs::name_pairs(vector<string> n, vector<double> a)
	:names{ n }, ages{ a }
{

}

name_pairs::name_pairs()
	: names{}, ages{} {}

name_pairs read_names(name_pairs np)
{
	cout << "Enter in a list of names to be added, type q to quit\n";
	string s;
	cin >> s;
	while (s != "quit") {
		np.names.push_back(s);
		cin >> s;
	}
	return np;
}

name_pairs read_ages(name_pairs np)
{
	cout << "Enter a list of ages to go with each name.\n";
	double d;
	for (int i = 0; i < np.names.size(); ++i) {
		cout << np.names[i] << ": ";
		cin >> d;
		np.ages.push_back(d);
		cout << np.names[i] << " is " << np.ages[i] << " years old.\n";
	}
	return np;
}

void print(name_pairs np)
{
	for (int i = 0; i < np.names.size(); ++i) {
		cout << np.names[i] << ", age: " << np.ages[i] << endl;
	}
	return;
}

void foo()
{
	name_pairs np = name_pairs();
	np = read_names(np);
	np = read_ages(np);
	print(np);
	keep_window_open();
	return;
}

int main()
{
	cout << "Enter a list of names followed by quit.\n";
	cout << "Then enter a list of ages for the list of names. \n";
	foo();
	return 0;
}