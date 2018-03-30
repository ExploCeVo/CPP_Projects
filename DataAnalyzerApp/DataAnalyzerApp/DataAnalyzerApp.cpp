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

using namespace DataAnalyzer;

String s;

Account::Account()
	: username{}, acctype{} {}

Account::Account(String username)
	: username{  s }, acctype{} {}

void main()
{
	return;
}

