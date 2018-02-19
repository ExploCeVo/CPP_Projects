
/*
Chapter6.cpp
==================================================================================
Contains the program worked on in chapter 6 and 7 of
Programming Principles and Practice using C++.

Described Grammer for this program:
==================================================================================
Statement:
	Expresssion
	Print
	Quit
Print:
	';'
Quit:
	'q'
Expression:
	Term
	Expression + Term
	Expression - Term
Term:
	Primary
	Term * Primary
	Term / Primary
	Term % Primary
Primary:
	Number
	(Expression)
	-Primary
	+Primary
Number:
	floating-point-literal

Input comes from cin through Token_stream called ts
==================================================================================
Parts of this program were used from the book as I learned.
other things were added by myself later on.
==================================================================================
BUGS:
	Add functionality for MOD
	Do more intense debugging
==================================================================================
author: Cole Chapin
==================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// token struct, contains 3 types.
// 1. a token representing itself, or a defined constant.
// 2. a token representing a number, and the value associated.
// 3. a token representing a definition, and the name associated.
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string var) :kind(ch), name(var) { }
};

// Token_stream class
// bool full returns true when the buffer is full, false otherwise
// Token buffer is the token buffer used for the calculator
// get() returns the next token in the buffer
// void unget() puts the token back in the buffer and marks full true
// ignore ignores specified characters found in the buffer
class Token_stream {
	bool full;
	Token buffer;
public:
	// Constructor setting full to false and initializing buffer to 0
	Token_stream() :full(0), buffer(0) { }

	// declaration
	Token get();

	// all this function needs to do is put t back in the buffer, 
	// and mark full true
	void unget(Token t) { buffer = t; full = true; }
	
	// declaration
	void ignore(char);
};

// constants used for control-flow and parsing
const char let = 'L';
const char quit = 'Q';
const char sqr = 'F';
const char print = ';';
const char number = '8';
const char name = 'a';

// function that returns the next token in the buffer
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {	// let any of these characters
	case '(':		// represent themself by returning
	case ')':		// Token(ch)
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':		// let any of these tokens return
	case '0':		// with their assigned kind value
	case '1':		// as well as their numerical value
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
				s += ch;			// while the next char is a letter or number
			cin.unget();			// append it to the variable string
			if (s == "let") 
				return Token(let);
			if (s == "sqrt(")
				return Token(sqr);
			if (s == "quit")		// note: let returns 'L' whereas quit returns 'Q'
				return Token(quit);
			return Token(name, s);	// else return the name string 
		}
		error("Bad token");
	}
}

// function that ignores the current character c
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

// struct used to define a Variable for this project
// contains a name string, and a double value
struct Variable {
	string name;
	double value;

	// initialization
	Variable(string n, double v) :name(n), value(v) { }
};

// vector to hold all the name values
vector<Variable> names;
vector<Variable> functions;

// Token stream to hold a stream of tokens
Token_stream ts;

// more iterative way to search for a name in the vector
double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

// sets the variable s to d if it exists in the vector
void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

double define_value(string var, double val)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == var)
			error(var, "Defined twice.");
	names.push_back(Variable{ var, val });
	return val;
}

// returns true if s is declared in vector, false otherwise
bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

/*
==================================================================================
	Functions used by our described grammar set
==================================================================================
*/


double expression();

// 
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':		// if (, evaluate the expression inside
	{	
		double d = expression();
		t = ts.get();	// once expression is done, must be
		if (t.kind != ')') // followed by )
			error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

// calls primary, and deciphers between *,/, and %
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) 
			error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left = remainder(left, d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// calls term, deciphers between + and - 
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// checks for a string token, if proper tokens are found
// calls expression and returns a double
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') 
		error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) 
		error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

// implements the square_root functionality of the math library.
double square_root()
{								// Needs Testing
	Token t = ts.get();
	if (t.kind != 'S')
		error("Expected square root function");

	Token t2 = ts.get();
	if (t2.kind != number)
		error("expected an expression after sqrt( ");
	double d = expression();
	return sqrt(d);
}

// calls declaration, square_root, and expression depending
// on case statement
double statement()
{							// Needs Testing
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
		break;
	case sqr:
		return square_root();
	default:
		ts.unget(t);
		return expression();
	}
}

// function to help with error clean up
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

// function that starts all of the bullshit
// prompts user for input, if t = ;, continues to eat
// else if its quit, returns, else it prints result and statement()
void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) 
			return;

		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() {

	try {
		// predefine names:
	//	define_value("pi", 3.1415926535);	One or  both of these cannot
	//	define_value("e", 2.7182818284);	be stored as a fpl
											// either that or these can't 
											// be called outside the function
											// body, second is more likely
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c&& c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}