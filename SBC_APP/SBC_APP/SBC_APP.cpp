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

class Squad_List {
public:
	class Invalid {};

	Squad_List(string sn, double tc, vector<string> pn, vector<double> pr);
	Squad_List();


private:
	string squad_name;
	double total_cost;
	vector<string> player_name;
	vector<double> price;
};

Squad_List::Squad_List(string sn, double tc, vector<string> pn, vector<double> pr)
	:squad_name{ sn }, total_cost{ tc }, player_name{ pn }, price{ pr } {}

// default constructor
Squad_List::Squad_List()
	: squad_name{}, total_cost{} {}

void print_list()
{
	return;
}

int main()
{
	Squad_List sl = Squad_List();

}