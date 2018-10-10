// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
#include <cstring>
#include <ctype.h>

using namespace std;

void showMenu();

int main()
{
	// user inputs uppercase letter
	char input;

	// user inputs choice they want from menu
	int choice;

	// user inputs position for delete and insert node
	int position;

	LinkedList list;

	do {
		showMenu();
		cin >> choice;

		while (choice < 1 || choice > 6)
		{
			cout << "\nWrong menu choice." << endl;
			cin >> choice;
		}
		if (choice != 7)
		{
			switch (choice)
			{
			
			case 1:
				cout << "\nWhat letter do you wish to append?" << endl;
				cin >> input;
				// check if input is an uppercase letter
				list.checkLetter(input);
				do {
					if (list.checkLetter(input) == true) {
						list.appendNode(input);
					}
					else
					{
						cout << "\nInvalid, enter an uppercase letter." << endl;
						cin >> input;
						list.appendNode(input);
					}
				} while (list.checkLetter(input) == false);
				break;

			case 2:
				cout << "\nEnter uppercase letter you want to insert:" << endl;
				cin >> input;
				// check if input is an uppercase letter
				list.checkLetter(input);
				do {
					if (list.checkLetter(input) == true) {
						cout << "\nEnter node location you want to insert:" << endl;
						cin >> position;
						list.insertNode(input, position);
					}
					else
					{
						cout << "\nInvalid, enter an uppercase letter." << endl;
						cin >> input;
						list.insertNode(input, position);
						
					}
				} while (list.checkLetter(input) == false);
				break;

			case 3:
				cout << "\nWhich node do you want to delete?" << endl;
				cin >> position;
				list.deleteNode(position);
				break;

			case 4:
				list.displayList();
				break;

			case 5:
				list.reverseNode();
				cout << "The linked list has been reversed." << endl;
				break;

			case 6:
				cout << "\nEnter uppercase letter you want to search for:" << endl;
				cin >> input;
				// check if input is an uppercase letter
				list.checkLetter(input);
				do {
					if (list.checkLetter(input) == true) {
						list.searchNode(input);
					}
					else
					{
						cout << "\nInvalid, enter an uppercase letter." << endl;
						cin >> input;
						list.searchNode(input);
					}
				} while (list.checkLetter(input) == false);
				break;
			}
		}
	} while (choice != 7);
	return 0;
}

void showMenu()
{
	cout << "\nMain Menu:\n\n"
		<< "1. Append\n"
		<< "2. Insert\n"
		<< "3. Delete\n"
		<< "4. Print\n"
		<< "5. Reverse\n"
		<< "6. Search\n\n"
		<< "Please choose a menu option:" << endl;
}
