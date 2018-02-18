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
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const string prompt = "> ";
const string result = "= ";

// classes created for use in this program
class Variable {
public:
	string name;
	double value;
};

class Token
{
public:
	char kind;
	double value;
	string name;

	// inializations
	Token() {}
	Token(char ch) : kind{ ch } {}
	Token(char ch, double val) : kind{ ch }, value{ val } {}
	Token(char ch, string n) : kind{ ch }, name{ n } {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c); // discard characters up to and including a c
private:
	bool full{ false };
	Token buffer;
};

Token_stream ts;
vector<Variable> var_table;

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;

	switch (ch) {
	case ';':
	case 'q':
	case '(': case ')': case '-':
	case '+': case '*': case '/':
		return Token{ ch };
	
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ 8, val };
	}

	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;

			cin.putback(ch);
			if (s == declkey)
				return Token{ let };
			return Token{ name, s };
		}
		error("Bad Token.");
	}
}

void Token_stream::putback(Token t)
{
	if (full)
		error("putback() into a full buffer");
	buffer = t;
	full = true;
}

// c represents the kind of Token
void Token_stream::ignore(char c)
{
	// first look in the buffer
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	// now search input
	char ch = 0;
	while (cin >> ch) {
		if (ch == c)
			return;
	}
}

double expression();
double term();
double primary();
void calculate();
void clean_up_mess();
double statement();
double declaration();

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
	case '\b':
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
	while (cin)
		try{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();

		if (t.kind == quit) {
			keep_window_open();
			return;
		}
		ts.putback(t);
		cout << result << statement() << '\n'; // Uses statement instead of expression()
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();
	}
}

// function that will replace expression
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

// clean up yo shit
void clean_up_mess()
{
	ts.ignore(print);
}

// returnn the value of variable named s
double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
}

// set the Variable of s to d
void set_value(string s, double d)
{
	for(Variable& v: var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}

// checks if var is already in var_table
bool is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var)
			return true;
	return false;
}

// add { var, val} to var_table
double define_name(string var, double val)
{
	if (is_declared(var))
		error(var, "declared twice");
	var_table.push_back(Variable{ var, val });
	return val;
}

// assume we have seen "let"
// handle: name = expression
// declare a variable called "name"
// with the initial value "expression"
double declaration()
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missin in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}