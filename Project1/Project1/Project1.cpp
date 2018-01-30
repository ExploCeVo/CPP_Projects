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
 *TODO*
 Begin implementing the login function, it should:
 a) Prompt user to enter username and password.
 b) If correct, basic result that says it worked. 
 c) If not, say attempt failed.

 Implement reg() function, it should:
 a) Prompt user to enter a username and re-enter, and then confirm they are the same. *DONE*
 b) Prompt user to enter a password and re-enter, and confirm they are the same. *DONE*
 c) Present messages saying if either failed. *DONE*
 d) If successful, create a file that will be able to hold data for the account. *DONE*
 e) If failed, prompted to retry or close the app. *BUGGED*
===============================================================================================
 *BUGS*
	Infinite loop with reg(), probably line 145.
===============================================================================================
Functions
	start():
		Starts the client.
	login():
		If user selects Login, proceeds to login screen.
	reg():
		If user selects Register, proceeds to register screen
===============================================================================================
last edit: 1/29/18
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
int reg();

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
		exit(3);
		break;
	default:
		// not sure if this is the proper way this should be handled, but throws 
		// an exception is thrown
		try {
			error("Invalid request.\n");
		}
		catch (exception& e) {
			keep_window_open("q");
	}
	}
	return(0);
}

// login function
void login()
{
	string name;
	string pass;

	cout << "Login\n";
	cout << "Username: ";
	cin >> name;
	cout << "\nPassword: ";
	cin >> pass;
}

// register function
int reg()
{
	ofstream outputFile;
	string user1, user2;
	string pass1, pass2;
	char ans;
	bool success = false;
	bool retry = true;

	while (retry) {
		cout << "Welcome to Registration\n";
		cout << "Enter a desired username: ";
		cin >> user1;
		cout << "\nRe-enter username: ";
		cin >> user2;
		cout << "\nEnter a desired password: ";
		cin >> pass1;
		cout << "\nRe-enter password: ";
		cin >> pass2;

		if (user1 != user2) {
			cout << "\n Usernames did not match.\n";
			cout << "Retry or press q to quit.\n";
			cin >> ans;
			if (ans == 'q') {
				exit(1);
			}
		}

		if (pass1 != pass2) {
			cout << "\n Passwords did not match.\n";
			cout << "Retry or press q to quit.\n";
			cin >> ans;
			if (ans == 'q') {
				exit(2);
			}
		}
		if (ans == 'r') continue;
		else break;
	}

	outputFile.open("accountdata.txt");
	outputFile << user1 << endl;
	outputFile << pass1 << endl;
	outputFile.close();
	cout << "Congratulations, you are officially registered!\n";
	keep_window_open();
	return 0;
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
