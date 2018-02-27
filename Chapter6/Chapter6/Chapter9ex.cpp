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
	vector<string> name;
	vector<double> age;
};

void read_names(vector<string>& n)
{
	while (cin) {
		string s;
		cin >> s;
		if (s == "quit") break;
		n.push_back(s);
	}
}

void read_ages(vector<string>& n, vector<double>& a)
{
	for (int i = 0; i < n.size(); ++i) {
		cout << "Enter an age for " << n[i] << ':';
		double age;
		cin >> age;
		a.push_back(age);
	}
}

void print(vector<string>& n, vector<double>& a)
{
	for (int i = 0; i < n.size(); ++i) 
		cout << n[i] << ": " << a[i];
	return;
}

void sort()
{
	//TODO
	// sort based off names and reassign ages
}

int main()
{
	try {
		cout << "Enter a list of names followed by quit.\n";
		cout << "Then enter a list of ages for the list of names. \n";
		read_names(n);
		read_ages(n, a);
	}
}