/*
Chapter9Book.h
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace mylib_1 {
	
	class Book {
	public:
		class Invalid {};

		Book(string is, string tt, string aa, string cc);

		// default constructor
		Book();

		string tisbn() const { return isbn; }
		string ttitle() const { return title; }
		string tauthor() const { return author; }
		string tcpyright() const { return cpyright; }
		bool tavail() const { return avail; }
		// non-modifying operations

		void check_out(Book& b);
		void check_in(Book& b);
		// modifying operations

	private:
		string isbn;
		string title;
		string author;
		string cpyright;
		bool avail;
	};

	bool validISBN(Book& b);
	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);
	ostream& operator<<(ostream& s, const Book& b);
} // mylib_1