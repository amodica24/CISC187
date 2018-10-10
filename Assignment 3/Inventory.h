/*
*
* Anthony Modica
*
* Chapter 13, Classes
*
* July 10, 2018
*
* Inventory.h
*
* Specification file for the Inventory class
*
*/

// include files
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

using namespace std;

class Inventory
{

private:
	int itemNumber;
	string itemDesc;
	string custLastName;
	string custPhone;
	float priceQuoted;
	float hoursWorked;

public:

	// default constructor
	Inventory()
	{
		itemNumber = 0; itemDesc = "";
		custLastName = ""; custPhone = "";
		priceQuoted = 0; hoursWorked = 0;
	}

	// Constructor #2
	Inventory(int item, string desc, string lastName, string phone, float quoted, float hours)
	{
		itemNumber = item;
		itemDesc = desc;
		custLastName = lastName;
		custPhone = phone;
		priceQuoted = quoted;
		hoursWorked = hours;
	}

	// mutators
	// these functions accepts the input arguments from the user
	void setItemNumber(int);
	void setItemDesc(string);
	void setCustLastName(string);
	void setCustPhone(string);
	void setPriceQuoted(float);
	void setHoursWorked(float);

	// accessors
	// these functions receive the input from the user and displays the data back
	int getItemNumber() const
	{
		return itemNumber;
	}

	string getItemDesc() const
	{
		return itemDesc;
	}

	string getCustLastName() const
	{
		return custLastName;
	}

	string getCustPhone() const
	{
		return custPhone;
	}

	float getPriceQuoted() const
	{
		return priceQuoted;
	}

	float getHoursWorked() const
	{
		return hoursWorked;
	}
};

#endif
