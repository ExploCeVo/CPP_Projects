/*
SBC_APP.cpp

 ==========================================================================================
 Grammer, currently a work in progress:

 Statement:
	Create List
	Add
	View List
	Quit
View List:
	"View"
Quit:
	"Quit"
Create List:
	List_Name
	"Create"
Add:
	Player
	Price
Player:
	String
Price:
	floating-point-literal
List_Name:
	String
 ==========================================================================================
 CURRENT IMPLEMENTATIONS:
	The players vector should be more or less working properly, will be easier to test once
	some work is done as far as grabbing examples from the console.

	Implementation of Token_stream::get() needs some work

	Functionality of the outer parts of the program need some work
 ==========================================================================================
	TODO:
	Implement the current grammar and test it

	Implement Outer functionality of the program
 ==========================================================================================
 last edit: 2/18/18
 author: Cole Chapin
 ==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// player struct
struct Player {
public:
	string name;
	double value;

	// initialization
	Player(string s, double v) : name(s), value(v) {}
};

// token struct
struct Token
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

// Token_stream class
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() : full(0), buffer(0) {}

	Token get();

	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

vector<Player> players;
Token_stream ts;

// puts token in buffer and marks it full
void Token_stream::unget(Token t)
{
	buffer = t;
	full = true;
}

// grabs next token from buffer
Token Token_stream::get()
{
	//TODO
}

// ignores char c in the token stream
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c)
			return;
}

/*
==========================================================================================
Helper Functions for data struct
==========================================================================================
 */

double get_cost(string nm)
{
	for(int i = 0; i < players.size; i++)
		if (players[i].name == nm) 
			return players[i].value;
	error(nm, "Is not in the current list.\n");
}

// sets the cost of player nm to cst if player is found in the list, otherwise an 
// error is thrown. This helper method might not be necessary
void set_cost(string nm, double cst)
{
	for(int i = 0; i < players.size; i++)
		if (players[i].name == nm) {
			players[i].value == cst;
			return;
		}
	error("Player not found in the list: ", nm);
}

// adds player to list, if player is already found in list, throws an error
void add_player(string nm, double cst)
{
	for (int i = 0; i < players.size; i++)
		if (players[i].name == nm)
			error(nm, "Is already in the list.\n");
	players.push_back(Player{ nm, cst });
	return;
}

// returns true if player is in list, false otherwise
bool in_table(string nm)
{
	for (int i = 0; i < players.size(); ++i)
		if (players[i].name == nm)
			return true;
	return false;
}

// Prints the full list of players to the console
void print_list()
{
	if (players.size < 0)
		error("List is Empty");
	for (int i = 0; i < players.size; i++)
		cout << players[i].name << ": " << players[i].value << endl;
	return;
}

/*
==========================================================================================
Other Functions
==========================================================================================
*/

void display()
{
	//TODO
}

int main() 
{
	//TODO
}