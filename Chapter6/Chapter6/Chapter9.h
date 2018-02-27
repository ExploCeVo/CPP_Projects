/*
Fun with classes
Chapter 8
Programming Principles and Practice using C++
Header file for Chapter 9 exercise
Chapter9.h

Date:
==========
y:  |  2005  |
m:  |   12   |
d:  |   24   |
==========
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace Chrono {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug,
		sep, oct, nov, dec
	};

	class Date {
	public:
		class Invalid {};			// exception throws

		Date(int yy, Month mm, int dd);
		// check for valid date
		Date();						// default constructor
									// default copy operations are fine

									// non modifying operations
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		// modifying operations
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d);	// true for valid date
	bool leapyear(int y);					// true if y is leap year
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& s, const Date& d);
	istream& operator >> (istream& is, const Date& d);

	//Day day_of_week(const Date& d);		// day of week of d
	Date next_Sunday(const Date& d);	// next Sunday after d
	Date next_weekday(const Date& d);	// next weekday after d
} // namespace Chrono
