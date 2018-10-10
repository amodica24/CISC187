/*
*
* Anthony Modica
*
* Chapter 19, Stacks and Queues
*
* July 31, 2018
*
* MathStack.cpp
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

// ********************************************************
// name:      push
// called by: main
// passed:    nothing
// returns:   nobody
// calls:     nobody
// The push function pushes an integer the user input onto the top of the stack
// ********************************************************
void MathStack::push(int val)
{
	StackNode *newNode = nullptr; // Pointer to a new node
								  // Allocate a new node and store num there.
	newNode = new StackNode;
	newNode->value = val;
	// If there are no nodes in the list
	// make newNode the first node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert NewNode before top.
	{
		newNode->next = top;
		top = newNode;
	}
}

// ********************************************************
// name:      pop
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The pop function removes an integer the user input from the stack
// ********************************************************
int MathStack::pop(int val)
{
	StackNode *nodePtr = top; // Temporary pointer
	StackNode *current = nullptr;

	if (nodePtr->value == val) { // check if the first pointer is the integer being popped
		top = top->next;         // stores the next node into the top node
		return 1;
	}

	while (nodePtr->next != nullptr) { // go through the stack until the end
		if (nodePtr->next->value == val) 
		{ // check for integer to be popped
			nodePtr->next = nodePtr->next->next; // place the next node into its previous node
			return 1;			
		}
		nodePtr = nodePtr->next; // increment the nodePtr
	}
	cout << "\nSorry, but " << val << " is not in the current stack" << endl; // checks if the integer value is in the stack
	return -1;
}

// ********************************************************
// name:      addStack
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The addStack function adds and pops the top two values from the stack and pushes the result onto the top
// ********************************************************
int MathStack::addStack()
{
	int firstNode, secondNode, result;

	while (isEmpty()) // checks if stack is empty 
	{
		cout << "\nInvalid operation, cannot add if stack is empty, " 
			<< "push at least two integers." << endl;
		return -1;
	}
	while (top->next == nullptr) // checks if stack contains only one integer
	{
		cout << "\nInvalid operation, cannot add is stack contains one integer, "
			<< "push at least one more integer." << endl;
		return -1;
	}
		cout << "\nAdded the first two numbers & replaced them with their sum!" << endl;
		firstNode = top->value; // copies the value in the top of the stack
		pop(top->value); // removes this value from the stack

		secondNode = top->value; // copies the new value in the top of the stacl 
		pop(top->value); // removes this value from the stack
		
		result = firstNode + secondNode; // adds the two copies
		push(result); // pushes the result on the top of the stack
		return 1;
}

// ********************************************************
// name:      subStack
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The subStack function substracts and pops the top two values from the stack and pushes the result onto the top
// ********************************************************
int MathStack::subStack()
{
	int firstNode, secondNode, result;

	if (isEmpty()) // checks if stack is empty 
	{
		cout << "\nInvalid operation, cannot substract if stack is empty, "
			 << "push at least two integers." << endl;
		return -1;
	}
	else if (top->next == nullptr) // checks if stack contains only one integer
	{
		cout << "\nInvalid operation, cannot substract if stack contains one integer, "
			<< "push at least one more integer." << endl;
		return -1;
	}
	else
	{
		cout << "\nSubtracted the first two numbers & replaced them with their difference!" << endl;
		firstNode = top->value; // copies the value in the top of the stack
		pop(top->value); // removes this value from the stack

		secondNode = top->value; // copies the new value in the top of the stacl 
		pop(top->value); // removes this value from the stack

		result = firstNode - secondNode; // substracts the two copies
		push(result); // pushes the result to the top of the stack
		return 1;
	}
}

// ********************************************************
// name:      mulStack
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The mulStack function multiplies and pops the top two values from the stack and pushes the result onto the top
// ********************************************************
int MathStack::mulStack()
{
	int firstNode, secondNode, result;

	if (isEmpty()) // checks if stack is empty 
	{
		cout << "\nInvalid operation, cannot multiply if stack is empty, "
			 << "push at least two integers." << endl;
		return -1;
	}
	else if (top->next == nullptr) // checks if stack contains only one integer
	{
		cout << "\nInvalid operation, cannot multiply if stack contains one integer, "
			<< "push at least one more integer." << endl;
		return -1;
	}
	else
	{
		cout << "\nMultiplied the first two numbers & replaced them with the result!" << endl;
		firstNode = top->value; // copies the value in the top of the stack
		pop(top->value); // removes this value from the stack

		secondNode = top->value; // copies the new value in the top of the stacl 
		pop(top->value); // removes this value from the stack
		
		result = firstNode * secondNode; // multiplies the two copies
		push(result);  // pushes the result to the top of the stack
		return 1; 
	}
}

// ********************************************************
// name:      divStack
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The divStack function divides and pops the top two values from the stack and pushes the result onto the top
// ********************************************************
int MathStack::divStack()
{
	int firstNode, secondNode, result;

	if (isEmpty()) // checks if stack is empty 
	{
		cout << "\nInvalid operation, cannot divide if stack is empty, "
			<< "push at least two integers." << endl;
		return -1;
	}
	else if (top->next == nullptr) // checks if stack contains only one integer
	{
		cout << "\nInvalid operation, cannot divide if stack contains one integer, "
			<< "push at least one more integer." << endl;
		return -1;
	}
	else if (top->next->value == 0) // checks if the second value in the stack is a 0
	{
		cout << "\nDivide by zero error!"; // display error message
		return -1;
	}
	else
	{
		cout << "\nDivided the first two numbers & replaced them with the result!" << endl;
		firstNode = top->value; // copies the value in the top of the stack
		pop(top->value); // removes this value from the stack

		secondNode = top->value; // copies the new value in the top of the stacl 
		pop(top->value); // removes this value from the stack

		result = firstNode / secondNode; //divides the two copies 
		push(result); // pushes the result to the top of the stack
		return 1;
	}
}
// ********************************************************
// name:      dispStack
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The dispStack function displays the values on the current stack
// ********************************************************
int MathStack::dispStack()
{
	if (isEmpty()) // check if stack is empty
	{
		cout << "\nThe current stack is empty." << endl;
		return -1;
	}
	else
	{
		cout << "\nHere is the current stack:" << endl;
		for (StackNode *newNode = top; newNode != nullptr; newNode = newNode->next)
		{
			cout << newNode->value << endl; // displays the stack until it reaches the end
		}
	}
	return 1;
}

// ********************************************************
// name:      isEmpty
// called by: main
// passed:    nothing
// returns:   true. false
// calls:     nobody
// The isEmpty function checks if the stack is empty or not
// ********************************************************
bool MathStack::isEmpty()
{
	bool flag;

	if (!top)
	{	// stack is empty
		flag = true;
	}

	else
	{	// else, stack isn't empty
		flag = false;
	}
	return flag;
}

// ********************************************************
// name:      isInteger
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The isInteger function checks whether or not the user input an integer
// ********************************************************
int MathStack::isInteger()
{
	int x;
	cin >> x; // user inputs an integer

	while (cin.fail()) // checks to see if the input is an integer and not a char
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "\nInvalid input, please enter an integer." << endl;
		cin >> x; // user re-enters integer
	}
	return x; // if an integer, return the value
}
