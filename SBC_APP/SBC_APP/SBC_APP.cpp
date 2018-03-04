/**
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
get_name()
get_total()
update_name()
update_total()
add_player()
player_cost()
print_list()
---------------------------
startup()
run() - will eventually run all the menu type functions	
==========================================================================================
TODO:
Create a basic menu

Token and Token_Stream currently in progress 
Will first test the Token class followed by the Token_Stream

Basic error checking

all classes for this application can be found in SBC_APP.h
==========================================================================================
last edit: 2/28/18
author: Cole Chapin
==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"
#include "SBC_APP.h"

using namespace mySBC;

Squad_List::Squad_List(string sn, double tc, vector<string> pn, vector<double> pr)
	:squad_name{ sn }, total_cost{ tc }, player_name{ pn }, price{ pr } {}

// default constructor
Squad_List::Squad_List()
	: squad_name{}, total_cost{} {}

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

// Initial startup
void startup()
{
	cout << "SBC_APP version 0.1.0." << endl;
	cout << "Use one of the following commands to get started:" << endl;
	cout << "1) Create a squad" << endl;
	cout << "2) View an existing squad" << endl;
	cout << "3) Exit application." << endl;
	keep_window_open();
	return;
}

// will eventually run everything
void run()
{
	startup();
}

// function to test ideas
void test()
{
	//test
	cout << "Enter a String." << endl;
	char ch;
	cin >> ch;

	// eats whitespace as intended
	while (iswspace(ch))
		cin >> ch;
	
	// checks if input was a word
	if (isalpha(ch)) {
		cin.unget();
		string s;
		cin >> s;
		cout << s << endl;
	}

	// if it was a number, try to solve the fucking problem
	else if (isdigit(ch)) {
		cout << "Did you mean to assign a price to a player?" << endl;
		cout << "Enter a name of the player to assign the price to." << endl;

		cin.unget();
		double d;
		cin >> d;
		string s;
		cin >> s;
		
	}
}

// main
int main()
{
	test();
	keep_window_open();
	return 0;
}