/*
Chapter 6-7 notes and exercises from Programming Practices and Principles.
==========================================================================
CREATING A PROGRAM
==========================================================================

==========================================================================
EXAMPLE OF A GRAMMAR EXPRESSION (UNCODED VERSION)
==========================================================================
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
==========================================================================
==========================================================================
COMPLETEING A PROGRAM
==========================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"


// constant definitions
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

// classes created for use in this program
class Variable {
public:
	string name;
	double value;
};

// class definitions
class Token
{
public:
	char kind;
	double value;
	string name;

	// inializations
	Token(char ch) : kind{ ch } {}
	Token(char ch, double val) : kind{ ch }, value{ val } {}
	Token(char ch, string n) : kind{ ch }, name{ n } {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

Token_stream ts;
vector<Variable> var_table;

double expression();
double term();
double primary();
void calculate();

// main function to run everything
int main()
{
	try {
		calculate();
		keep_window_open();
		return 0;
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
		keep_window_open("~");
		return 1;
	}
	catch (...) {
		cerr << "Exception\n";
		keep_window_open("~");
		return 2;
	}
}

// deal with + and -
//calls term() and get_token()
double expression()
{
	double left = term();		// read and evaluate an expression
	Token t = ts.get();			// get the next token
	while (true) {
		switch (t.kind) {		// see which kind of token it is
		case'+':
			left += term();		// eval term and add
			t = ts.get();
			break;
		case '-':
			left -= term();		// eval term and sub
			t = ts.get();
			break;
		default:
			ts.putback(t);		// put t back into tokenstream
			return left;		// finally, no more + or -, return answer
		}
	}
}

// deal with numbers, parenthesis, and negative numbers
// calls expression() and get_token()
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected \n");
		return d;
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("Primary expected\n");
	}
}

// deal with *, /, and %
// calls primary() and get_token()
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("cannot divide by 0.\n");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%:Cannot divide by 0.\n");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

// performs calculations for the program
void calculate()
{
	while (cin) {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();

		if (t.kind == quit) {
			keep_window_open();
			return;
		}
		ts.putback(t);
		cout << result << expression() << '\n';
	}
}