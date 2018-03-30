/*
DataAnalyzerApp.h
Header file
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

namespace DataAnalyzer {
	class Account {
	public:

		class Invalid {};

		Account();
		Account(String name);

		// name of account 
		String getname() const { return username; }
		// type of account
		String gettype() const { return acctype; }

	private:
		String username;
		String acctype;

	};
}