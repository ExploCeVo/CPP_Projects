/*
Chapter 6 notes and exercises from Programming Practices and Principles.
=========================================================================
CREATING A PROGRAM
=========================================================================

=========================================================================
EXAMPLE OF A GRAMMAR EXPRESSION
=========================================================================
Expression:
	Term
	Expression "+" Term		// addition
	Expression "-" Term		// subtraction

Term:
	Primary
	Term "*" Primary		// multiplication
	Term "/" Primary		// division
	Term "%" Primary		// remainder (mod)

Primary:
	Number
	"(" Expression ")"		// grouping

Number:
	floating-point-literal
=========================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"


//  Defined functions
int calc_ex1();

// main function to run everything
int main()
{
	calc_ex1();
    return 0;
}

// Bad example of a calculator because it improperly handles the use of PEMDAS.
// but it is a start
int calc_ex1()
{

	cout << "Please enter expression, (we can handle +, -, *, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";

	int lval = 0;
	int rval;
	cin >> lval;				// read in left most operand

	if (!cin) error("No First Opperand.");
	for (char op; cin >> op;) {	// read operator and right-hand operand
								// repeatedly
		if (op != 'x') cin >> rval;
		if (!cin) error("No second Operand.");
		switch (op) {
		case '+':
			lval += rval;		// add: lval = lval + rval
			break;				// etc etc etc.
			
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:				// not another operator: print result
			cout << "Result: " << lval << '\n';
			system("pause");
			return(0);
		}
	}
	system("pause");
	error("bad expression");	// u fucked boi
}



