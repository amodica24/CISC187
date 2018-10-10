/*
*
* Anthony Modica
*
* Chapter 13, Classes
*
* July 10, 2018
*
* main.cpp
*
* Additional files needed to compile this program:
* Inventory.h
* Inventory.cpp
*
*/

// include files
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Inventory.h"
#include <string>
#undef max

using namespace std;

// constant of number of repairs 
const int NUM_REPAIR = 5;
int main()
{
	// array of Inventory objects
	Inventory repair[NUM_REPAIR];

	int itemNumber;
	string itemDesc;
	string custLastName;
	string custPhone;
	float priceQuoted;
	float hoursWorked;

	float totalHours = 0.0;
	cout << "Joseph's Computer Repair\n" << endl;
	cout << "Input the following data:" << endl;

	// the user is prompted to input a value or string
	// the program will set, or store these values into its specified function

	for (int i = 0; i < NUM_REPAIR; i++)
	{
		cout << "\n";
		// get the item number
		cout << setw(10) << left << "Item:";
		cin >> itemNumber;  // user inputs the value
		repair[i].setItemNumber(itemNumber); // input then goes to the function, and runs until the loop ends

											 // get the item description
		cout << setw(10) << left << "Desc:";
		cin.ignore(1000, '\n'); // ignores 1000 characters or until the first encountered instance of the new line character from the input stream
		getline(cin, itemDesc); // consumes all characters up to, and including, the new line character. It then throws away the new-line, and stores the input string in itemDesc
		repair[i].setItemDesc(itemDesc);

		// get the customer's last name
		cout << setw(10) << left << "Cust:";
		getline(cin, custLastName);
		repair[i].setCustLastName(custLastName);

		// get the customer's phone number
		cout << setw(10) << left << "Phone:";
		getline(cin, custPhone);
		repair[i].setCustPhone(custPhone);

		// get the quoted price of the repair
		cout << setw(10) << left << "Quote:";
		cin >> priceQuoted;
		repair[i].setPriceQuoted(priceQuoted);

		// get the hours worked on the repair
		cout << setw(10) << left << "Hours: ";
		cin >> hoursWorked;
		repair[i].setHoursWorked(hoursWorked);
	}

	cout << "\nHere is the data you just entered:" << endl;
	// the terminal will display the data collected from the user
	for (int i = 0; i < NUM_REPAIR; i++)
	{
		cout << "\n";
		cout << setw(10) << left << "Item:" << repair[i].getItemNumber() << endl;
		cout << setw(10) << left << "Desc:" << repair[i].getItemDesc() << endl;
		cout << setw(10) << left << "Cust:" << repair[i].getCustLastName() << endl;
		cout << setw(10) << left << "Phone:" << repair[i].getCustPhone() << endl;
		cout << setw(10) << left << "Quote:" << "$" << repair[i].getPriceQuoted() << endl;
		cout << setw(10) << left << "Hours:" << repair[i].getHoursWorked() << endl;

		// calculates total hours
		totalHours += repair[i].getHoursWorked();
	}
	cout << "\nTotal Hours: " << setw(5) << totalHours << endl;
}
