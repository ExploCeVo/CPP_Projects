/*
Header File for SBC_APP
SBC_APP.h
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace mySBC {

	Token_stream ts;

	class Squad_List {
	public:
		class Invalid {};

		Squad_List(string sn, double tc, vector<string> pn, vector<double> pr);
		Squad_List();

		string get_sq_name() const { return squad_name; }
		double get_total() const { return total_cost; }

		void update_squad_name(string s);
		double update_total();
		void add_player(string s);
		void player_cost(double d);
		void print_list();
		bool Squad_List::has_player(string s);

	private:
		string squad_name;
		double total_cost;
		vector<string> player_name;
		vector<double> price;
	};

	class Token {
	public:
		Token(char ch) : kind(ch), value(0) {}
		Token(char ch, string s) : kind(ch), name(s)  {}
		Token(char ch, double v) : kind(ch), value(v) {}
		 
	private:
		char kind;
		double value;
		string name;
	};

	class Token_stream {
	public:
		Token_stream() : full(0), buffer(0) {}
		Token get();
		void ignore();
		void unget(Token t) {buffer = t; full = true;}

	private:
		bool full;
		Token buffer;
	};

} // namespace mySBC