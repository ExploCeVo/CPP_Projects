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

	vector<string> name_list() const { return names; }
	vector<double> age_list() const { return ages; }

	void read_names();
	void read_ages();

private:
	vector<string> names;
	vector<double> ages;
};

name_pairs::name_pairs(vector<string> n, vector<double> a)
	:names{ n }, ages{ a } 
{

}

name_pairs default_pair()
{
	name_pairs np{};
	return np;
}

void read_names(name_pairs np)
{
	cout << "Enter in a list of names to be added, type q to quit\n";
	string s;
	cin >> s;
	while (s != "quit") {
		np.name_list().push_back(s);
	}
}

void foo()
{
	name_pairs np = default_pair();
	read_names(np);
	return;
}

int main()
{
		cout << "Enter a list of names followed by quit.\n";
		cout << "Then enter a list of ages for the list of names. \n";
		foo();
		return 0;
}