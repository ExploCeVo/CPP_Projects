/*
==========================================================================================
SBC_APP.cpp ==============================================================================
==========================================================================================
==========================================================================================
Grammer, currently a work in progress: (Isn't very specific at this point, more progress
needs to be made).

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
Squad_List functions:
print_list()
get_name()
get_total()
update_name()
update_total()
add_player()
player_cost()
has_player()
------------------------------------------------------------------------------------------
Token_stream functions:
get()
ignore()
putback(Token t)
------------------------------------------------------------------------------------------
Local functions:
startup()
run() - will eventually run all the menu type functions
test()
main()
==========================================================================================
TODO:
Simplify commands until there is a single working unit to build off of (1)
Create a basic menu (1)
Menu Navigation (2)
Advanced token checking (4)
Basic error checking (3)
==========================================================================================
all classes for this application can be found in SBC_APP.h
==========================================================================================
last edit: 3/19/18
author: Cole Chapin
==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"
#include "SBC_APP.h"

using namespace mySBC;

// CONSTANT VARIABLES
const char		QUIT =			'q';
const char		PLAYER_TOK =	'1';
const char		VALUE_TOK =		'2';
const char		CREATE	=		'3';
const char		VIEW =			'4';
const char		PROMPT =		'>';

// LOCAL VARIABLES
Token_stream	ts;

// specific constructor
Squad_List::Squad_List(string sn, double tc, vector<string> pn, vector<double> pr)
	:squad_name{ sn }, total_cost{ tc }, player_name{ pn }, price{ pr } {}

// default constructor
Squad_List::Squad_List()
	: squad_name{}, total_cost{} {}

// function to print out the squad name, and the list of players and prices
void Squad_List::print_list()
{
	cout << "Squad Name: " << squad_name << endl;
	for (int i = 0; i < player_name.size(); ++i) {
		cout << "Player: " << player_name[i] << ", Cost: " << price[i] << endl;
	}
	cout << "Total Cost: " << total_cost << endl;
	return;
}

// function that updates the squad name
void Squad_List::update_squad_name(string s)
{
	squad_name = s;
}

// function that updates the total cost for the squad
double Squad_List::update_total()
{
	total_cost = 0;
	for (int i = 0; i < price.size(); ++i)
		total_cost += price[i];
	return total_cost;
} 

// function that adds a player to the player_name vector
void Squad_List::add_player(string s)
{
	player_name.push_back(s);
}

// function that adds a price to the price vector
void Squad_List::player_cost(double d)
{
	price.push_back(d);
}

// function that checks if a player is in the list of players
bool Squad_List::has_player(string s)
{
	for (int i = 0; i < player_name.size(); ++i) {
		if (s == player_name[i]) {
			return true;
		}
		return false;
	}
}

// token get function, returns the proper Token.
// needs some error handing and extra checks
// works well enough for now
Token Token_stream::get()
{
	// check if buffer is full
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;

	if (isdigit(ch)) {
		cin.unget();
		double d;
		cin >> d;
		return Token(VALUE, d);
	}

	if (isalpha(ch)) {
		cin.unget();
		char c;
		cin >> c;
		if (c == QUIT)
			return Token(QUIT);
		//todo 
	}
	else error("Bad Token Nigger.");
}

// function that ignores certain tokens caught by the get() function
void Token_stream::ignore()
{
	//todo
}

// current in progress functions....
void create_squad()
{
	//todo
}
void view_squad()
{
	//todo
}

// Initial startup
void startup()
{
	cout << "SBC_APP version 0.1.1." << endl;
	cout << "Use one of the following commands to get started:" << endl;
	cout << "1) Create a squad" << endl;
	cout << "2) View an existing squad" << endl;
	cout << "3) Exit application." << endl;
	return;
}

// will eventually run everything -- needsd work
void run()
{
	startup();

	while (1) {
		cout << PROMPT;
		Token t = ts.get();
		if (t.kind == QUIT)
			return;

		ts.unget(t);
		// handle menu options
		// depending on choice
		// start with build a new menu
		// prompt squad name followed by a list of players and prices
	}
}

// should be turned into a kind check function eventually
void test()
{

	startup();
	keep_window_open();
	return;
}

// function that handles menu functionality
void command_list()
{
	Token t = ts.get();
	if (t.kind == CREATE) {
		create_squad();
	}

	if (t.kind == VIEW) {
		view_squad();
	}

}

// main
int main()
{
	test();
	keep_window_open();
	return 0;
}