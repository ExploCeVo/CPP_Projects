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
	lookupList(); TODO

	Very little error checking created thus far, focused more on raw results.

 last edit: 2/13/18
 author: Cole Chapin
 ==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"


// constant definitions and variables

int prompt();
void test();
bool isFloat(string myString);
void createList();
void lookupList();

// main hehe
void main()
{
	test();
} 

// function to test if entered string could be converted to a float
bool isFloat(string myString) {
	std::istringstream iss(myString);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
						  // Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

// Runs prompt() and createList()
void test()
{
	int ans = prompt();
	keep_window_open();
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
	playerList.open("playerdata.txt");
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

// lookups current file containing a list of players and their prices
void lookupList()
{
	return;
}