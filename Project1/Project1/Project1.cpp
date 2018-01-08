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

===============================================================================================
Functions
	start():
		Starts the client.
	login():
		If user selects Login, proceeds to login screen.
	reg():
		If user selects Register, proceeds to register screen
===============================================================================================
last edit: 1/7/18
===============================================================================================
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// starts the program
int start()
{
	cout << "Please enter either Login or Register followed by Enter. \n";
	string ans;
	cin >> ans;

	if (ans == "Login") {
		cout << "Please enter username and password.\n";
		string user;
		string pass;
		cout << "Username: ";
		cin >> user;
		cout << "\nPassword: ";
		cin >> pass;
		cout << "Checking Authentication...\n";
	}

	if (ans == "Register") {
		cout << "Please Enter Designated username and password.\n";
		cout << "Username :\n";
		string user;
		string pass1, pass2;

		cin >> user;
		cout << "Password: \n";
		cin >> pass1;
		cout << "Re-Enter Password: \n";
		cin >> pass2;
	}
	
	system("pause");
	return(0);
}

//login function
void login()
{
	//todo
}

//register function
void reg()
{
	//todo
}

// file open and save example, will be used for saving data later on
int ex1()
{
	ofstream outputFile;
	outputFile.open("program3data.txt");

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
	cout << "Done!\n";
	return(0);
}

int main(int argv, char argc[])
{
	ex1();
}


