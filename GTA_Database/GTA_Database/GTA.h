/*
Header file for GTA_Database
GTA_Database.h
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace GTA {

	class client_list {
	public:
	private:
	};

	struct Token {
		Token(char ch) : kind(ch), value(0) {}
		Token(char ch, string s) : kind(ch), name(s) {}

		char kind;
		double value;
		string name;
	};

	class token_stream {
	public:
		token_stream() : full(0), buffer(0) {}
		Token get();
		void ignore();
		void unget(Token t) { buffer = t; full = true; }
	
	private:
		bool full;
		Token buffer;
	};
} // namespace GTA