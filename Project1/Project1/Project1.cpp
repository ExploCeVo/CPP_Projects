/*
Project 1

Some sort of database system that uses data storage. Will Evolve as knowledge of CPP increases.

===============================================================================================
Profile:
	Name
	Age
	Address
	Phone
	Current balance
===============================================================================================
 * TODO
 Create the start function, to begin it should:
 a) Prompt user to login, register or exit. DONE
 b) If login or register is selected, send a message confirming its entered the proper function. DONE
 c) If exit is selected, send a message saying entered exit function and then console closes. 
 d) Throw an error if either of these is not selected. DONE

 Once these work, edit it so that it stores information in a simple text file.
===============================================================================================
Functions
	start():
		Starts the client.
	login():
		If user selects Login, proceeds to login screen.
	reg():
		If user selects Register, proceeds to register screen
===============================================================================================
last edit: 1/20/18
===============================================================================================
*/

// includes
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities.h"

// function definitions
int start();
void login();
void reg();
void exit();

// main function
int main(int argv, char argc[])
{
	start();
}

// starts the program
int start()
{
	cout << "Welcome to my shitty application. Respond appropriately or else.\n";
	cout << "1) Login\n";
	cout << "2) Register\n";
	cout << "3) Quit\n";

	char ans;
	cin >> ans;

	switch (ans) {
	case '1':
		login();
		break;
	case '2':
		reg();
		break;
	case '3':
		exit();
		break;
	default:
		// not sure if this is the proper way this should be handled, but throws 
		// an exception is thrown
		try {
			throw 20;
		}
		catch (int e) {
			cout << "Go see a doctor about getting a helmet. Exception number: " << e << '\n';
		}
		break;
	}
	return(0);
}

// login function
void login()
{
	cout << "Welcome to the login function\n";
	keep_window_open();
}

// register function
void reg()
{
	cout << "Welcome to the register function\n";
	keep_window_open();
}

// exit function
void exit()
{
	cout << "Welcome to the exit function\n";
	keep_window_open();
}

// file open and save example, will be used for saving data later on
int ex1()
{
	ofstream outputFile;
	outputFile.open("accountdata.txt");

	float num1, num2, num3, num4, num5;

	cout << "Enter the first number: ";
	cin >> num1;
	outputFile << num1 << endl;
	cout << "Enter the second number: ";
	cin >> num2;
	outputFile << num2 << endl;
	cout << "Enter the third number: ";
	cin >> num3;
	outputFile << num3 << endl;
	cout << "Enter the fourth number: ";
	cin >> num4;
	outputFile << num4 << endl;
	cout << "Enter the fifth number: ";
	cin >> num5;
	outputFile << num5 << endl;

	outputFile.close();
	return(0);
}
