// hw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

// function
void showMenu();

// ********************************************************
// name:      displayArray
// called by: main
// passed:    int array
// returns:   nothing
// calls:     nobody
// The displayArray function displays the elements of array1 to the command terminal
// ********************************************************

void displayArray(int array1[5][5])
{
	for (int i = 0; i < 5; i++) // Loop through the rows
	{
		for (int j = 0; j < 5; j++) // Loop through the columns
		{
			cout << setw(5) << right << array1[i][j] << "  ";		// Display the elements in the array
		}
		cout << endl;
	}
}

// ********************************************************
// name:      tripleArray
// called by: main
// passed:    int array1
// returns:   int array1
// calls:     nobody
// The tripleArray function multiplies the each element in array1 by three
// ********************************************************

void tripleArray(int array1[][5])
{
	for (int i = 0; i < 5; i++)			 // loop through the row and columns
	{
		for (int j = 0; j < 5; j++)
		{
			array1[i][j] *= 3;			// multiplies the elements of array1 by 3
		}
	}
	cout << "The array is multiplied by 3.";
}

// ********************************************************
// name:      swapArray
// called by: main
// passed:    int array1
// returns:   int array1
// calls:     nobody
// The swapArray function swaps row 2 and 3 with each other.
// ********************************************************

void swapArray(int array1[][5])
{
	for (int i = 0; i < 5; i++)
	{
		int temp;
		temp = array1[1][i];			// make a copy of the second row
		array1[1][i] = array1[2][i];	// move elements of third row to second row
		array1[2][i] = temp;			// place third row elements into the second row 
	}
	cout << "The elements in rows 2 and 3 are swapped.";
}


// ********************************************************
// name:      sumArray
// called by: main
// passed:    int array1
// returns:   total
// calls:     nobody
// The sumArray function sums the total elements in array2
// ********************************************************

void sumArray(int array1[][5]) {
	double total = 0;					// holds the value of the total number of elements

	for (int i = 0; i < 5; i++)			// loop through the row and columns
	{
		for (int j = 0; j < 5; j++)
		{
			total += array1[i][j];		// total value of elements from array2
		}								// expected value is -1170
	}
	cout << "The sum of the array is:" << total << endl;
}

int main()
{
	int array1[5][5] = { { 1, 2, 3, 4, 5 },{ -20, -40, -60, -80, -100 },{ 3,3,3,3,3 },{ 5, 7, 9, 11, 13 },{ -5, -25, -35, -45, -55 } };

	int choice;
	const int showArray = 1,
		multiplyArray = 2,
		swapRow = 3,
		addArray = 4,
		exit = 5;
	cout << fixed << showpoint << setprecision(1);

	do {
		showMenu();
		cin >> choice;										// user input

		while (choice < showArray || choice > exit) {		// user has to input between 1 and 5, else an error shows up 
			cout << "Wrong Menu Choice";
			cin >> choice;
		}

		if (choice != exit)									// if the user inputs any number besides 5, then
		{
			switch (choice)
			{
			case showArray:									// if they choose 1, display the array
				displayArray(array1);
				break;
			case multiplyArray:								// or if they choose option 2, multiply the array by 3
				tripleArray(array1);
				break;
			case swapRow:									// or if they choose option 3, swap swap rows 2 and 3 with each other
				swapArray(array1);
				break;
			case addArray:									// or if they choose option 4, display the sum of all the elements in the array
				sumArray(array1);
				break;
			}
		}
	} while (choice != exit);								// else, if they choose option 5, then the program exits
	return 0;
}

void showMenu()
{
	cout << "\nMain Menu: \n\n"
		<< "1. Display Array\n"
		<< "2. Multiply each element in the array by 3\n"
		<< "3. Swap the values in row two with the values in row three.\n"
		<< "4. Calculate the SUM of all elements and display that number.\n"
		<< "5. Exit\n\n";
}
