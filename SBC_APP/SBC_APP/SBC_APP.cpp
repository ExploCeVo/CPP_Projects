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

Token_stream ts;
vector<Variable> var_table;
// constant definitions and variables
const string FileName = "playerdata.txt";
const char name = 'N';
const char number = '8';
const char add = 'A';
const string decakey = "add";

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
double get_value(string s);
void set_value(string s, double d);
bool is_declared(string var);
double define_name(string var, double val);

// declarations not used by var_table
int prompt();
void test();
bool isFloat(string myString);
void createList();
void lookupList();

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

// calls prompt(), createList(), and lookupList()
void test()
{
	int ans = prompt();
	if (ans == 1) createList();
	if (ans == 2) lookupList();
	if (ans == 3) return;
	if (ans == 4)
		error("Invalid Entry.\n");
}

// Initial prompt for app
int prompt()
{
	cout << "Welcome to the SBC version. 0.0.2.\n";
	cout << "Press 1 to create a list, or 2 to view a current list.\n";
	cout << "Press 3 to quit.\n";
	char ans;
	cin >> ans;
	switch (ans) {
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	default:
		cout << "Invalid entry, dickhead. Closing...\n";
		return 4;
		break;
	}
}

// creates a text file containing a list of the player names and prices
void createList()
{
	cout << "Please enter a player name followed by cost.\n";
	cout << "Enter 'done' when you've finished filling the list.\n";

	ofstream playerList;
	string input;
	playerList.open(FileName);
	if (playerList.is_open()) {
		while (cin) {
			cin >> input;
			if (input == "done" || input == "Done" ||
				input == "done." || input == "Done.") {
				playerList.close();
				cout << "List created.\n";
				break;
			}

			if (!isFloat(input)) {
				cout << "Player Name: " << input << '\n';
				playerList << "Player" << endl;
				playerList << input << endl;
				continue;
			}

			if (isFloat(input)) {
				cout << "Player Cost: " << input << '\n';
				playerList << "Price" << endl;
				playerList << input << endl;
				continue;
			}
		}
	}
	else cout << "Unable to open file.\n";
	return;
}

// lookups current file containing a list of players and their prices
void lookupList()
{
	ifstream list;
	string line;
	list.open(FileName);
	if (list.is_open()) {
		while (getline(list, line)) {
			cout << line << endl;
		}
		list.close();
	}
	else error("Unable to open file");
	keep_window_open();
	return;
}

/*
==========================================================================================
	FUNCTIONS USED BY VAR_TABLE
==========================================================================================
*/

// return the variable of the Variable named s
double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: Undefined Variable", s);
}

// set the variable named s to d
void set_value(string s, double d)
{
	for(Variable& v: var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("Set: undefined Variable.", s);
}

// check if var is already in var_table
bool is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

// add {var, val} to var_table
double define_name(string var, double val)
{
	if (is_declared(var)) error(var, "declared twice");
	var_table.push_back(Variable{ var, val });
	return val;
}