/*
Fun with constexpr
Chapter 8
Programming Principles and Practice
*/

#include "stdafx.h"
#include "std_lib_facilities.h"

struct Point {
	double x;
	double y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
};

// scaling values
constexpr double xscale = 10;
constexpr double yscale = 0.8;

// scaling function, returns p.x and p.y with new scaled values
constexpr Point scale(Point p)
{
	return xscale* p.x, yscale* p.y;
};

// Calculates at runtime, will only work if constants are passed
// else will be an error
void user(Point p1)
{
	Point p2{ 10,10 }; // constant

	Point p3 = scale(p1);	// p3 = {100, 8}
	constexpr Point p4 = scale(p2);	// p4 == {100, 8}
	constexpr Point p5 = scale(p1);	// error: p1 not a constant expr
	constexpr Point p6 = scale(p2);	// p6 == {100, 8}
}

// Constructing global constants properly
// Constructs Date every time default_date() is called, we only want 
// this performed once so that it is not expensive to do so
const Date& default_date()
{
	static const Date dd(1970, 1, 1);
	return dd;
}
// static local variable is initialized onlyl the first time its function
// is called