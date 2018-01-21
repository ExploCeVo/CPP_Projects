/* 
Chapter4.cpp : Examples from Programming Principles and Practice

Notes: 

constexpr: defines a constant

===============================Operators=====================================
			Name						Comment
f(a)	funct. call			pass a to f as an assignment
++Ival	pre-increment		increment and use the incremented value
--Ival	pre-decrement		decrement and use the decremented value
!a		not					result is bool
-a		unary minus
a*b		multiply
a/b		divide
a%b		modulo				only for int types
a+b		add
a-b		subtract
out<<b	write b to out		where out is an outstream
in>>b	read from in to b	where in is an instream
=============================================================================
=================
Switch Statements
=================
A common example of selection is to use a simple charater unit.

Better than nested if loops.

Value presented after the parenthesis in the switch statement is compared.
to a set of constraints.
Each constraint is presented as part of a case label.
If the value equals the constant in the case label, the statement is chosen.

- Switch technicalities

Values used must be an int, char or an enumerated type.
Cannot switch on a string.

Values in case labels must be constant expressions.

=====================
Function Declarations
=====================
Declare with #include.
int square(int);
double sqrt(double); // examples of declarations of functions

*/
#include "stdafx.h"
#include "std_lib_facilities.h"

using namespace std;

// very basic if loop
int ex4_1()
{
	int a = 0;
	int b = 0;

	cout << "Please enter two integers\n";
	cin >> a >> b;

	if (a < b)
		cout << "max(" << a << "," << b << ") is " << b << "\n";
	else
		cout << "max(" << a << "," << b << ") is " << a << "\n";

	system("pause");
	return(0);
}

// basic conversion function
int ex4_2()
{
	constexpr double cm_per_inch = 2.54;

	double length = 1;
	char unit = 0;

	cout << "Please enter a length followed by a unit (c or i):\n";
	cin >> length >> unit;

	if (unit == 'i')
		cout << length << "in == " << cm_per_inch*length << "cm\n";
	else
		cout << length << "cm == " << cm_per_inch*length << "in\n";
	system("pause");
	return(0);
}

// examples with switch statements
int ex4_3()
{
	constexpr double cmperinch = 2.54;
	double length = 1;
	char unit = 'a';

	cout << "Please enter a length followed by a unit (c or i): \n";
	cin >> length >> unit;

	switch (unit) {
	case 'i':
		cout << length << "in == " << cmperinch*length << "cm\n";
		break;
	case 'c':
		cout << length << " cm == " << cmperinch*length << "in\n";
		break;
	default:
		cout << "Sorry, idk wtf u just said yo " << unit << '\n';
		break;
	}
	system("pause");
	return(0);
}

// example 4, takes a list of tempuratures from user and outputs average and mean
int vec_ex1()
{
	vector<double> temps;
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	// compute mean temp
	double sum = 0;
	for (double x : temps) 
		sum += x;
	cout << "Average Tempurature: " << sum / temps.size() << '\n';

	// compute median temp
	sort(temps);
	cout << "Median Tempurature: " << temps[temps.size() / 2] << '\n';
	
	system("pause");
	return(0);
}

// vector example 2, simple dictionary example
// use ctrl+z to stop intaking input
int vec_ex2()
{
	vector<string> words;

	for (string temp; cin >> temp; )
		words.push_back(temp);
	cout << "Number of words: " << words.size() << '\n';
	sort(words);

	for (int i = 0; i < words.size(); ++i)
		if (i == 0 || words[i - 1] != words[i]) // is this a new word?
			cout << words[i] << '\n';
	system("pause");
	return(0);
}

// function that runs everthing
int main(int argc, _TCHAR* argv[])
{
	vec_ex2();
	return 0;
}