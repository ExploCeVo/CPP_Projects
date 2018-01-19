/*
Chapter 6 notes and exercises from Programming Practices and Principles.
=========================================================================
CREATING A PROGRAM
=========================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"


int main()
{
    return 0;
}

int calc_ex1()
{

	cout << "Please enter expression, (we can handle +, -, *, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";

	int lval = 0;
	int rval;
	cin >> lval;

	if (!cin) error("No First Opperand.");
	for (char op; cin >> op;) {

		if (op != 'x') cin >> rval;
		if (!cin) error("No second Operand.");
		switch (op) {
		case '+':
			lval += rval;
			break;
			
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		}
	}
	system("pause");
	return 0;
}

