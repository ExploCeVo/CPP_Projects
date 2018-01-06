/*
Contains examples from chapter 3 of Programming Practices and Principles.
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// simple program to exercise operators
int op_ex1()
{
	cout<< "Please enter a floating-point value: ";
	double n;
	cin>> n;
	cout<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n*n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< '\n';
	keep_window_open();
	return(0);
}

// read first and second name
int op_ex2()
{
	cout << "Please enter your first and second names\n";
	string first;
	string second;
	cin >> first >> second;				// read two strings
	string name = first + ' ' + second;	// concatenate those strings
	cout << "Hello, " << name << '\n';
	keep_window_open();
	return(0);
}

// read and compare names
int op_ex3()
{
	cout << "Please enter two names\n";
	string first;
	string second;

	cin >> first >> second;
	if (first == second) cout << "thats the same name twice\n.";
	if (first < second)
		cout << first << " is aphabetically before " << second << '\n';
	if (first > second)
		cout << first << " is alphabetically after " << second << '\n';
	keep_window_open();
	return(0);
}

// runs everything
int main()
{
	op_ex3();
    return 0;
}