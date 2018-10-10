/*
*
* Anthony Modica
*
* Chapter 19, Stacks and Queues
*
* July 31, 2018
*
* main.cpp
*
* Additional files needed to compile this program:
* MathStack.h
*
*/

// include files
#include "stdafx.h"
#include <iostream>
#include "MathStack.h"

using namespace std;

void showMenu();

int main()
{
	// user inputs choice they want from menu
	int choice;

	// user inputs the integers for the push and pop functions
	int num;

	MathStack stacks;

	do {
		showMenu();
		choice = stacks.isInteger(); // check if a integer

		while (choice < 1 || choice > 8)
		{
			cout << "\nError, wrong menu choice." << endl;
			choice = stacks.isInteger();
		}

		if (choice != 9)
		{
			switch (choice)
			{
			// case 1: pushes the integer onto the top of the stack
			case 1:
				cout << "\nEnter an integer you want to push onto the stack:" << endl;
				num = stacks.isInteger(); // check if integer
				stacks.push(num); // push the integer onto the stack
				break;
			
			// case 2: pops an integer from the stack
			case 2:
				if (stacks.isEmpty()) // first check if the stack is empty before going through the stacks.pop() function
				{
					cout << "\nInvalid operation, the stack is empty, push at least one ineteger onto the stack." << endl;
				}
				else 
				{
					cout << "\nEnter the integer you want to pop off the stack:" << endl;
					num = stacks.isInteger(); // check if integer
					stacks.pop(num); // pop the integer from the stack
				}
				break;
			
			// case 3: adds the top two integers in the stack and replaces them with the sum
			case 3:
				stacks.addStack();
				break;
			
			// case 4: substracts the top two integers in the stack and replaces them with the difference
			case 4:
				stacks.subStack();
				break;
			
			// case 5: multiplies the top two integers in the stack and replaces them with the result
			case 5:
				stacks.mulStack();
				break;
			
			// case 6: adds the top two integers in the stack and replaces them with the result
			case 6:
				stacks.divStack();
				break;
			
			// case 7: displays the current stack
			case 7:
				stacks.dispStack();
				break;

			// case 8: exit program
			case 8:
				cout << "\nGoodbye!" << endl;
				exit(EXIT_FAILURE);
				break;

			}
		}
	} while (choice != 9);
	return 0;
}

// ********************************************************
// name:      showMenu
// called by: main
// passed:    nothing
// returns:   nobody
// calls:     nobody
// The showMenu function displays the menu for the user to choose from
// ********************************************************
void showMenu()
{
	cout << "\nMain Menu:\n\n"
		<< "1. Push\n"
		<< "2. Pop\n"
		<< "3. Add\n"
		<< "4. Subtract\n"
		<< "5. Mult\n"
		<< "6. Div\n"
		<< "7. Display Stack\n"
		<< "8. End\n\n"
		<< "Please choose a menu option:" << endl;
}
