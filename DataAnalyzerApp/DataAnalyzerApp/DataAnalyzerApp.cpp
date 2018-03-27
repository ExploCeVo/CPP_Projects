/*
=====================================================================================================
DataAnalyzerApp.ccpp
Application intended to take various forms of data and provide mathematical calculations, checks etc.
=====================================================================================================

=====================================================================================================
Idea   ----   Start
Figure out a list of options the user is interested in doing.
 Things could be:
	Cost effectivesy 
	merchant profit
	analysis on previous investments
	
	these should be more than just numbers, accounts that tie to a bunch of listened numbers with a 
	history. daily change, etc.

buy something? how much for

sell something? how much for

eventually look into deals
=====================================================================================================
author: Cole Chapin
=====================================================================================================
*/

#include "stdafx.h"
#include "std_lib_facilities.h"
#include "DataAnalyzerApp.h"

namespace DataAnalyer {
	class AccountType {
	public:

		class Invalid {};

		AccountType();
		AccountType(String username);

		// name of account 
		String getname() const { return username;}
		// type of account
		String gettype() const { return acctype; }
		
	private:
		String username;
		String acctype;

	};
}
int main()
{
    return 0;
}

