/*
*
* Anthony Modica
*
* Chapter 21, Binary Tree
*
* August 11, 2018
*
* main.cpp
*
* Additional files needed to compile this program:
* IntBinaryTree.h
*
*/

// include files
#include "stdafx.h"
#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

void showMenu();

int main()
{
	// user inputs choice they want from menu
	int choice;

	// user inputs the integer
	int num;

	IntBinaryTree tree;

	do {
		showMenu();
		choice = tree.isInteger(); // check if a integer

		while (choice < 1 || choice > 6)
		{
			cout << "\nError, wrong menu choice." << endl;
			showMenu();
			choice = tree.isInteger();
		}

		if (choice != 7)
		{
			switch (choice)
			{
			
			// case 1: pushes the integer onto the top of the stack
			case 1:
				cout << "\nEnter an integer you want to insert in the Binary Tree:" << endl;
				num = tree.isInteger(); // check if integer
				tree.insertNode(num); // inserts the node into the binary tree
				break;
				
			// case 2: displays the tree in order
			case 2:
				if (tree.isEmpty()) // first check if binary tree is empty
				{
					cout << "\nThe current binary tree is empty, insert at least one integer." << endl;
				}
				else
				{
					cout << "\nHere is the tree:" << endl;
					tree.displayInOrder(); // display the tree in order
				}
				break;
			
			// case 3: counts the number of tree leaf
			case 3:
				cout << "\nThe tree leaf count is: " << tree.leafCount() << endl;
				break;
			
			// case 4: displays the height of the tree
			case 4:
				cout << "\nHeight of the tree is: " << tree.height() << endl;
				break;

			// case 5: displays the width of the tree
			case 5:
				cout << "\nEnter the level you want to find the width of:" << endl;
				num = tree.isInteger();
				while (num < 0)
				{
					cout << "\nInvalid input, enter a value greater than 0." << endl;
					num = tree.isInteger();
				}
				cout << "\nThe width of level " << num << " is " << tree.width(num) << endl;
				break;

			// case 6: exit program
			case 6:
				cout << "\nGoodbye!" << endl;
				exit(EXIT_FAILURE);
				break;

			}
		}
	} while (choice != 7);
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
		<< "1. Insert numbers\n"
		<< "2. Display the tree (in order)\n"
		<< "3. Display Leaf Count\n"
		<< "4. Display Tree Height\n"
		<< "5. Display Tree Width\n"
		<< "6. End\n\n"
		<< "Note: The level begins at 0.\n\n"
		<< "Please choose a menu option:" << endl;
}
