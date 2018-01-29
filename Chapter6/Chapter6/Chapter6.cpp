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


// class definitions
class Token
{
public:
	char kind;
	double value;
};
class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

// implementing helper functions from class Token_stream
void Token_stream::putback(Token t)
{
	buffer = t;
	full = true;
}

// Token_stream get() helper function
Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;	// >> skips whitespace like space, newline, tab, etc.

	switch (ch) {
	case ';':	// for "print"
	case 'q':	// for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		error("Bad Token");
	}
}

Token_stream ts;
double expression();
double term();
double primary();

// deal with numbers and parenthesis
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
	case '8':
		return t.value;
	default:
		error("Primary expected\n");
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
			if (d == 0) error("don't divide by 0\n");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

// main function to run everything
int main()
{
	try {
		double val = 0;
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'q') break;
			if (t.kind == ';')
				cout << "=" << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}
		keep_window_open();
		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Exception\n";
			keep_window_open();
			return 2;
		}
}