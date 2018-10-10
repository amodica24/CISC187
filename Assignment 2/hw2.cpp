/*
*
* Anthony Modica
*
* Chapter 9 Review - Pointers
*
* July 3, 2018
*
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

// length of array
const int length = 25;

// function prototypes
void showMenu();
void displayArray(int *point, int size);
void tripleArray(int *point, int size);
void sumArray(int *point, int size);
void swapArray(int *point, int size);

int main() {
	int array1[length] = { 1, 2, 3, 4, 5, -20, -40, -60, -80, -100, 3,3,3,3,3,5, 7, 9, 11, 13, -5, -25, -35, -45, -55 };

	int *point; // declare pointer
	point = array1; // point to array

	int choice;

	do {
		showMenu();
		cin >> choice; // user input

		while (choice < 1 || choice > 5) { // user has to input between 1 and 5, else an error shows up 
			cout << "Wrong Menu Choice, Try Again";
			cin >> choice;
		}

		if (choice != 5)
		{
			switch (choice)
			{
			case 1:
				displayArray(array1, length);
				break;
			case 2:
				tripleArray(array1, length);
				break;
			case 3:
				swapArray(array1, length);
				break;
			case 4:
				sumArray(array1, length);
				break;
			}
		}
	} while (choice != 5);
	return 0;
}

// ********************************************************
// name:      showMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The showMenu function displays the menu for the user to choose from
// ********************************************************

void showMenu()
{
	cout << "\nMain Menu: \n\n"
		<< "1. Display Array\n"
		<< "2. Multiply each element in the array by 3\n"
		<< "3. Swap the values in row two with the values in row three.\n"
		<< "4. Calculate the SUM of all elements and display that number.\n"
		<< "5. Exit\n\n"
		<< "Input values 1-4, or 5 to exit:  ";

}

// ********************************************************
// name:      displayArray
// called by: main
// passed:    int array
// returns:   nothing
// calls:     nobody
// The displayArray function displays the elements of array1 to the command terminal
// ********************************************************

void displayArray(int *point, int size) {
	for (int i = 0; i < length; i++) 
	{
		cout << setw(5) << right << *(point + i) << " "; // displays all the elements
		if ((i + 1) % 5 == 0) // once the pointer reaches a multiple of 5, make a new row
		{ 
			cout << endl;
		}
	}
}

// ********************************************************
// name:      tripleArray
// called by: main
// passed:    int array1
// returns:   int array1
// calls:     nobody
// The tripleArray function multiplies each element in array1 by 3
// ********************************************************

void tripleArray(int *point, int size) {
	for (int i = 0; i < length; i++)
	{
		*(point + i) *= 3; // multiplies the element where the pointer is by 3
	}
	cout << "The array was multiplied by 3" << endl;
}

// ********************************************************
// name:      swapArray
// called by: main
// passed:    int array1
// returns:   int array1
// calls:     nobody
// The swapArray function swaps row 2 and 3 with each other.
// ********************************************************

void swapArray(int *point, int size) {
	for (int i = 0; i < 5; i++) 
	{
		int temp = *(point + i + 5);      // make a copy of the 2nd row elements
		*(point + i + 5) = *(point + i + 10); // moves the 2nd row elements to the 3rd row
		*(point + i + 10) = temp;         // moves the 3rd row elements to the copy of the 2nd row
	}
	cout << "Rows 2 and 3 are swapped" << endl;
}

// ********************************************************
// name:      sumArray
// called by: main
// passed:    int array1
// returns:   total
// calls:     nobody
// The sumArray function sums the total elements in array2
// ********************************************************

void sumArray(int *point, int size) {
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(point + i);
	}
	cout << "The sum of the array is:" << sum << endl;
}
