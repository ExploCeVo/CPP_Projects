/*
SBC_APP.cpp

This application is intended to do the following:
 1. Take in a list of players and their estimated prices
 2. Store this list and display them until purchased on fifa 
 3. As players are purchased, user can enter amounts paid until entire team is bought
 4. Display total cost for purchased team
 5. Compare the total to the estimate as well as estimated worth of the packs earned
	from completing the certain sbc.
 6. yadayada

 il finish this bullshit later..
 ==========================================================================================
 CURRENT IMPLEMENTATIONS:
	prompt(); asks for a user prompt, and returns the proper int value according to answer.
	test(); function that runs everything currently being tested.
	isFloat(string myString); function checks if user input is a float.
	createList(); function that creates a list of players and prices, storing them in a
	text file.
	lookupList(); function opens a file and lists players and prices found.

	Added Variable, Token, and Token_stream classes to help with finding and eliminating
	errors.
	get() function needs some work, whether adding token checks or deleting some.
 ==========================================================================================
	TODO:
	Change from using a text file to store information to using the vector var_table. TODO
	Add functionality for printing current var_table as well as editing it. TODO
	Edit prompts to work with the new functionality. TODO
	WERE GETTING SOMEWHERE... KINDA
 ==========================================================================================
 last edit: 2/13/18
 author: Cole Chapin
 ==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

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
	Token(char ch, string n) : kind{ch}, name{n}{}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

// constant definitions and variables
const string FileName = "playerdata.txt";
const char name = 'N';
const char number = '8';
const char add = 'A';
const string decakey = "add";
Token_stream ts;
vector<Variable> plr_table;

// declarations used by Token_stream

// puts token in buffer and marks it full
void Token_stream::putback(Token t)
{
	buffer = t;
	full = true;
}

Token Token_stream::get()
{

	if (full) {	// check if we have already have a token ready
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;	// >> skips whitespace like space, newline, tab, etc.

	switch (ch) {
	case ';':	// for "print"
	case 'q':	// for "quit"
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return Token{ ch };	// let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ number, val };
	}
	default:
		if (isalpha(ch)) {
			cin.putback(ch);
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			if (s == decakey) return Token{ add };
			return Token{ name, s };
		}
		error("Bad Token");
	}
}

// declarations used by var_table
double get_price(string s);
void set_price(string s, double d);
bool in_list(string var);
double add_player(string var, double val);

// declarations not used by var_table
int prompt();
void test();
bool isFloat(string myString);

// main hehe
void main()
{
	test();
	return;
} 

// function to test if entered string could be converted to a float
bool isFloat(string myString) {
	std::istringstream iss(myString);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
						  // Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

// calls prompt()
void test()
{
	int ans = prompt();
		error("Invalid Entry.\n");
}

// initial prompt for app
int prompt()
{
	return 0;
}

/*
==========================================================================================
	FUNCTIONS USED BY VAR_TABLE
==========================================================================================
*/

// return the price of the player named plr
double get_price(string plr)
{
	for (const Variable& v : var_table)
		if (v.name == plr) return v.value;
	error("get: Undefined Variable", plr);
}

// set the player plr price to d
void set_price(string plr, double d)
{
	for(Variable& v: var_table)
		if (v.name == plr) {
			v.value = d;
			return;
		}
	error("Set: undefined Variable.", s);
}

// check if plr is already in var_table
bool in_list(string plr)
{
	for (const Variable& v : var_table)
		if (v.name == plr) return true;
	return false;
}

// add {plr, val} to plr_table
double add_player(string plr, double val)
{
	if (in_list(plr)) error(plr, "declared twice");
	var_table.push_back(Variable{ plr, val });
	return val;
}