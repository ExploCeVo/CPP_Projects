// GTA_Database.cpp : Defines the entry point for the console application.
//
// The purpose of this application is to play with a database that deals with
// ordering of products, specifications of those products, and storage of past 
// products for future reference.
//
//
// @author Cole Ross Chapin

#include "stdafx.h"
#include "std_lib_facilities.h"
#include "GTA.h"

using namespace GTA;

// CONSTANT VARIABLES
const char QUIT = 'q';
// LOCAL VARIABLES

Token token_stream::get()
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
		else error("Bad token");
	}
}
void startup()
{
	cout << "GTA_APP version 0.0.1" << endl;
	cout << "Use the following commands to get started:" << endl;
	cout << "1) Create a new entry" << endl;
	cout << "2) Look up an existing entry" << endl;
	cout << "3) Exit application." << endl;
	return;
}

int main()
{
    return 0;
}

