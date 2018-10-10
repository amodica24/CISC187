/*
*
* Anthony Modica
*
* Chapter 13, Classes
*
* July 10, 2018
*
* Inventory.cpp
*
* Implementation file for the Inventory class
*
* Additional files needed to compile this program:
* Inventory.h
*
*/

// include files
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Inventory.h"
#include <string>

using namespace std;

// ********************************************************
// name:      setItemNumber
// called by: main
// passed:    int itemNum
// returns:   nothing
// calls:     nobody
// The setItemNumber function accepts an integer argument that is copied to the itemNumber member
// the program exits if the input is less than 0.
// ********************************************************
void Inventory::setItemNumber(int itemNum)
{
	if (itemNum < 0)
	{
		// invalid if input is less than 0
		cout << "Input a number greater than 0.\n";
		exit(EXIT_FAILURE);
	}
	else
		itemNumber = itemNum;
}

// ********************************************************
// name:      setItemDesc
// called by: main
// passed:    string itemInfo
// returns:   nothing
// calls:     nobody
// The setItemDesc function accepts a string argument that is copied to the itemDesc member
// the program exits if the input is greater than or equal to 25 characters long.
// ********************************************************
void Inventory::setItemDesc(string itemInfo)
{
	int len = itemInfo.length();

	if (len >= 25)
	{
		// invalid if input is greater than or equal to 25
		cout << "Invalid, item description is too long.\n";
		exit(EXIT_FAILURE);
	}
	else
		itemDesc = itemInfo;
}

// ********************************************************
// name:      setCustLastName
// called by: main
// passed:    string name
// returns:   nothing
// calls:     nobody
// The setItemDesc function accepts a string argument that is copied to the setCustLastName member
// the program exits if the input is greater than or equal to 25 characters long.
// ********************************************************
void Inventory::setCustLastName(string name)
{
	int len = name.length();


	if (len >= 25)
	{
		// invalid if input is greater than or equal to 25
		cout << "Invalid, last name is too long.\n";
		exit(EXIT_FAILURE);
	}
	else
		custLastName = name;
}

// ********************************************************
// name:      setCustPhone
// called by: main
// passed:    string phoneNum
// returns:   nothing
// calls:     nobody
// The setCustPhone function accepts a string argument that is copied to the setCustPhone member 
// the program exits if the input is greater than or equal to 25 characters long.
// ********************************************************
void Inventory::setCustPhone(string phoneNum)
{
	int len = phoneNum.length();
	if (len >= 25)
	{
		// invalid if input is greater than or equal to 25
		cout << "Invalid, phone number is too long.\n";
		exit(EXIT_FAILURE);
	}
	else
		custPhone = phoneNum;
}

// ********************************************************
// name:      setPriceQuoted
// called by: main
// passed:    float prices
// returns:   nothing
// calls:     nobody
// The setPriceQuoted function accepts an integer argument to the priceQuoted member
//  the program exits if the input is less than 0.
// ********************************************************
void Inventory::setPriceQuoted(float prices)
{
	if (prices < 0)
	{
		// invalid if input is less than 0
		cout << "Invalid, input a number greater than 0.\n";
		exit(EXIT_FAILURE);
	}
	else
		priceQuoted = prices;
}

// ********************************************************
// name:      setHoursWorked
// called by: main
// passed:    float worked
// returns:   nothing
// calls:     nobody
// The setHoursWorked function accepts an integer argument that is copied to the setHoursWorked member 
// the program exits if the input is less than 0.
// ********************************************************
void Inventory::setHoursWorked(float worked)
{
	if (worked < 0)
	{
		// invalid if input is less than 0
		cout << "Invalid, input a number greater than 0.\n";
		exit(EXIT_FAILURE);
	}
	else
		hoursWorked = worked;
}
