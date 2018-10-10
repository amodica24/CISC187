/*
*
* Anthony Modica
*
* Chapter 19, Stacks and Queues
*
* July 31, 2018
*
* MathStack.h
*
*/

// include files
#ifndef MATHSTACK_H
#define MATHSTACK_H

class MathStack
{
private:
	// Structure for stack nodes
	struct StackNode
	{
		int value; // value in the node
		StackNode *next; // pointer for the next node
	};

	StackNode *top; // points to the top of the stack

public:
	// default constructor
	MathStack()
	{
		top = nullptr;
	}

	// mutator functions
	void push(int);
	int pop(int);
	int addStack();
	int subStack();
	int mulStack();
	int divStack();
	int dispStack();
	bool isEmpty();
	int isInteger();
};
#endif
