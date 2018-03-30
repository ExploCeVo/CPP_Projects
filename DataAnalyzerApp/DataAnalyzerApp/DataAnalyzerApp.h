/*
DataAnalyzerApp.h
Header file
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace DataAnalyer {
	class Account {
	public:

		class Invalid {};

		Account();
		Account(String name);
		Account()

		// name of account 
		String getname() const { return username; }
		// type of account
		String gettype() const { return acctype; }

	private:
		String username;
		String acctype;

	};
}