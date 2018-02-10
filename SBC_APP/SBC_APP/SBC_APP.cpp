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
 last edit: 2/10/18
 author: Cole Chapin
 ==========================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// class definitions
class Token
{
public:
	char player;
	int value;
};
class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

 // constant definitions and variables
bool isDone = false;
// input stream to hold tokens
Token_stream ts;

// puts token in buffer and marks it full
void Token_stream::putback(Token t)
{
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	while (!isDone) {
		string input;
		cin >> input;
		bool isPrice = isInt(input);
		
		if (!isPrice)
		{
			cin.putback(input);
		}
	}

}

inline bool isInt(const std::string& s);
int test1();

// main hehe
int main()
{
	test1();
} 

// no idea what this does but haha
inline bool isInt(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

// test code to fuck with
int test1() {
	std::cout << "Please, enter a number or a word: ";
	char c = std::cin.get();

	if ((c >= '0') && (c <= '9'))
	{
		int n;
		std::cin.putback(c);
		std::cin >> n;
		std::cout << "You entered a number: " << n << '\n';
	}
	else
	{
		std::string str;
		std::cin.putback(c);
		getline(std::cin, str);
		std::cout << "You entered a word: " << str << '\n';
	}
	return 0;
}