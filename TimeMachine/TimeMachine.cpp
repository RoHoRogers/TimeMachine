//Programmer: Kevin Rogers
//Lab 1 - TimeMachine.cpp : A program for CSS342 at University of Washington Bothell.
//Date: 10/12/2015
//A program which can take measurements of time in the form of hours, minutes, and seconds.  It can perform addition and subtraction on this class
//and output answers in both negative and positive.  A simple program detailing overloading operators.

#include "stdafx.h"
//#include <iostream>
#include "TimeSpan.h"
using namespace std;


int main()
{


	//tests for every instance

	TimeSpan testDur;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur5(-1, 2, 3), dur6, dur7(0,0,0);
	TimeSpan dur4 = dur3 - dur1;
	dur6 += dur3;
	dur6 -= dur5;

	cout << "Please input 3 numbers independantly: Hours, Minutes, Seconds." << endl << "(press enter after each one)" << endl;
	cin >> testDur;

	cout << testDur << endl;
	

	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;

	-dur5;
	cout << dur5 << endl;



	if (dur6 == dur5)
	{
		cout << "Durations are the same" << endl;
	}
	else
	{
		cout << "Durations are different." << endl;
	}

    return 0;
}

