/*
*
* Anthony Modica
*
* Chapter 20, Recursion
*
* August 7, 2018
*
* LinkedList.cpp
*
* Additional files needed to compile this program:
* LinkedList.h
*
*/

// include files
#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

// ********************************************************
// name:      appendNode
// called by: main
// passed:    char letters
// returns:   nothing
// calls:     nobody
// The appendNode function accepts a char argument
// this then inserts a char at the head of the linkedList (if linkedList is empty), or at the end (if linkedList is occupied)

void LinkedList::appendNode(char letters)
{
	ListNode *newNode; // points to a new node
	ListNode *nodePtr; // this moves through the list

					   // allocates and then stores char letters to newNode
	newNode = new ListNode;
	newNode->alpha = letters;
	newNode->next = nullptr;

	// if the linkedlist is empty, make newNode the first node
	if (isEmpty())
	{
		head = newNode;
	}

	else 	// if not, insert newNode at the end of the linkedList
	{
		// this initializes nodePtr to the head of the list
		nodePtr = head;

		// finds the last node in the list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		//inserts newNode as the last node
		nodePtr->next = newNode;
	}

}

// ********************************************************
// name:      insertNode
// called by: main
// passed:    char letters, int pos
// returns:   1, -1
// calls:     nobody
// The insertNode function accepts a char and int argument 
// where the program inserts letters in the given pos argument
// ********************************************************
int LinkedList::insertNode(char letters, int pos)
{
	ListNode *previousNode = new ListNode;
	ListNode *current = head;
	ListNode *temp = new ListNode;
	temp->alpha = letters;

	int elements = 0;

	// find the number of elements in the linked list
	// this will be used to verify if there is a pos based on elements
	while (current != nullptr) {
		current = current->next;
		elements++;
	}

	// if the linked list is empty, output an error message
	if (!head)
	{
		cout << "\nInvalid, the list is empty" << endl;
		return -1;

	} // if user inputs 0 as the node pos
	else if (pos == 0)
	{
		// store the address from head to temp
		// this places the user input into the first node (or 0)
		temp->next = head->next;
		head = temp;
	}
	else if (pos > 0 && pos < elements)
	{
		current = head;
		for (int i = 0; i < pos; i++)
		{
			previousNode = current; // shifts the nodes so that previousNode is the head
			current = current->next; // makes roomm for the inserted value
		}
		previousNode->next = temp; // places the value between previous and current
		temp->next = current;
	}

	else
	{
		// invalid if there is no position yet.
		cout << "Invalid, " << pos << " does not exist yet." << endl;
		return -1;
	}
	return -1;
}

// ********************************************************
// name:      deleteNode
// called by: main
// passed:    int pos
// returns:   1, -1
// calls:     nobody
// The deleteNode function accepts an int argument
// and deletes the character at that node position
// ********************************************************
int LinkedList::deleteNode(int pos)
{
	ListNode *current = head;
	ListNode *previousNode = nullptr;

	int elements = 0;

	// check first if the linked list is empty
	if (isEmpty())
	{
		cout << "\nInvalid operation, the linked list is empty." << endl;
		return -1;
	} // if user input 0, the next node is stored into head
	else if (pos == 0)
	{
		head = head->next;
	}
	else
	{ // go through elements until the current node reaches nullptr
		while (current != nullptr)
		{
			current = current->next; // contents of next stored into current
			elements++; // incremement the amount of elements in the list until current reaches nullptr
		}
		if (pos > 0 && pos < elements)
		{
			current = head;
			for (int i = 0; i < pos; i++)
			{
				previousNode = current;
				current = current->next;
			}
			previousNode->next = current->next;
			return 1;
		}
		else
		{
			cout << "\nThere is no position " << pos << " in the linked list." << endl;
			return -1;
		}
	}
	delete current; // deletes the current node that is at the specified location from the linked list
	return 1;
}

// ********************************************************
// name:      countNodes
// called by: main
// passed:    ListNode *nodePtr
// returns:   1, -1
// calls:     nobody
// The countNodes function returns the number of characters in the stack
// ********************************************************
int LinkedList::countNodes(ListNode *nodePtr) const
{
	// check when the nodePtr is at the end of the list

	if (nodePtr != nullptr)
	{
		// increment the amount of nodePtr and go back to the start of this function
		return 1 + countNodes(nodePtr->next); 
	}
	else
	{
		// once it reaches the end of the list, quit program
		return 0;
	}
}

// ********************************************************
// name:      largeAlpha
// called by: main
// passed:    ListNode* nodePtr, char bigAlpha
// returns:   1, -1
// calls:     nobody
// The largeAlpha function returns the largest character in the list
//
// ********************************************************
char LinkedList::largeAlpha(ListNode* nodePtr, char bigAlpha) const
{

	// ends the program by returning the largest character in the list
	// once it reaches the end of the program
	if (nodePtr == nullptr)
	{
		return bigAlpha;
	}

	// checks if there is a character bigger than the current biggest character
	if (nodePtr->alpha > bigAlpha)
	{
		bigAlpha = nodePtr->alpha;
	}
	
	// recursively go back to the start of this function
	return largeAlpha(nodePtr->next, bigAlpha);
}

// ********************************************************
// name:      displayList
// called by: main
// passed:    char letters, int pos
// returns:   1, -1
// calls:     nobody
// The displayList function displays the linkedList
// ********************************************************
void LinkedList::displayList() const
{
	ListNode *nodePtr;

	nodePtr = head;

	// if the linkedlist is empty, make newNode the first node
	if (!head)
	{
		cout << "\nThe linked list is empty." << endl;
	}
	else {
		cout << "\nHere is the linked list:" << "\n";
		while (nodePtr)
		{
			cout << nodePtr->alpha << endl;
			nodePtr = nodePtr->next;
		}
	}
}

// ********************************************************
// name:      reverseNode
// called by: main
// passed:    nothing
// returns:   nobody
// calls:     nobody
// The reverseNode function reverses the nodes on the linkedList
// ********************************************************
int LinkedList::reverseNode()
{
	ListNode *current = head;
	ListNode *next = nullptr;
	ListNode *previous = nullptr;

	while (current != nullptr)
	{

		next = current->next;
		current->next = previous;

		// the alpha in the current pointer is stored in previous
		previous = current;
		// the alpha in the next pointer is stored in current
		current = next;
	}
	head = previous;
	return 1;
}

// ********************************************************
// name:      searchNode
// called by: main
// passed:    char letters
// returns:   1, -1
// calls:     nobody
// The searchNode function accepts a char argument, and the program checks to see whether or not the char is in the linkedList
// ********************************************************
int LinkedList::searchNode(char letters)
{
	ListNode *nodePtr = head;
	int index = 0;

	// error message if linked list is empty
	if (isEmpty())
	{
		cout << "\nInvalid, the linked list is empty." << endl;
		return -1;
	}
	// go through linked list until nodePtr reaches nullptr
	while (nodePtr != nullptr)
	{
		if (nodePtr->alpha == letters)  // check if linked list contains user's input
		{
			cout << "\nThe character " << letters << " is at " << index;
			return 1;
		}

		else { // if not, go to the next node position
			nodePtr = nodePtr->next;
		}

		index++;
	}
	// after traversing linked list, if there was no inputted character, return error message
	cout << "\nInvalid, " << letters << " is not part of the linked list" << endl;
	return -1;
}

// ********************************************************
// name:      checkLetter
// called by: main
// passed:    char letters
// returns:   checkValid
// calls:     nobody
// The checkLetter function accepts a char argument which checks if the user input an uppercase letter
// ********************************************************
bool LinkedList::checkLetter(char letters)
{
	bool checkValid = false;

	if (isalpha(letters) && isupper(letters))
	{
		// if char letters is a letter and uppercase
		// set checkValid to true

		checkValid = true;
	}
	else
	{
		// else checkValid is false
		checkValid = false;
	}
	// return checkValid
	return checkValid;
}

// ********************************************************
// name:      isEmpty
// called by: main
// passed:    nothing
// returns:   true. false
// calls:     nobody
// The isEmpty function checks if the stack is empty or not
// ********************************************************
bool LinkedList::isEmpty()
{
	bool flag;

	if (!head)
	{	// stack is empty
		flag = true;
	}

	else
	{	// else, stack isn't empty
		flag = false;
	}
	return flag;
}
