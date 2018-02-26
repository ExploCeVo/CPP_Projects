/*
Fun with classes
Chapter 8
Programming Principles and Practice using C++
Chapter8.cpp

	Date:
	==========
y:  |  2005  |
m:  |   12   |
d:  |   24   |
	==========
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

// simple year class
class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) : y{ x } { if (x < min || max <= x) throw Invalid{}; }
	int year() { return y; }
private:
	int y;
};

// simple date
class Date {
public:
	class Invalid {};

	Date();
	Date(int y);
	Date(int y, Month m, int d);

	void add_day(int n);

	int Date::month()
	{
		return m;
	}

	int Date::day()
	{
		return d;
	}

	int Date::year()
	{
		return y;
	}

private:
	int y;	// year
	Month m;	// month
	int d;	// day

	bool is_valid();
};

// month enum class
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep,
	oct, nov, dec
};

// day enum class
enum class Day {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

Date today;	// a Date variable (named object)

// Default Constructor
Date::Date()
	:y{ 2000 }, m{ Month::jan }, d{ 1 } {}

// Constructor: January 1st of year y
Date::Date(int y)
	: y{ y }, m{ Month::jan }, d{ 1 } {}

// constructor
Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	y = yy;
	m = mm;
	d = dd;

	if (!is_valid()) throw Invalid{};
}

void Date::add_day(int n)
{
	// TODO
}

bool Date::is_valid()
{
	if (m < 1 || 12 < m)
		return false;
	if (d < 1 || 30 < d)
		return false;
	return true;
}

Month int_to_month(int x)
{
	if (x < int(Month::jan) || int(Month::dec) < x)
		error("bad month");
	return Month(x);
}

Month operator++(Month& m)
{
	// m becomes jan if (m==dec) and Month(int(m)+1) otherwise
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

vector<string> month_tbl;
 
// allowing << operator to be used for dates
ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[int(m)];
}

// check if entered values are valid, if they are
// initialize dd
void init_day(Date& dd, int y, int m, int d)
{
	
}

void f(int x, int y)
{
	try {
		Date dxy{ 2004, x, y };
		cout << dxy << '\n';
		dxy.add_day(2);
	}
	catch(Date::Invalid) {
		error("Invalid Date");
	}
}

// main
int main()
{

}