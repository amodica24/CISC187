/*
*
* Anthony Modica
*
* Chapter 20, Recursion
*
* August 7, 2018
*
* LinkedList.h
*
*/

// include files
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstring>

using namespace std;

class LinkedList
{
private:
	struct ListNode
	{
		char alpha;
		struct ListNode *next;
	};

	ListNode *head;

	int countNodes(ListNode *) const;
	int showReverse(ListNode *) const;
	char largeAlpha(ListNode*, char) const;

public:
	LinkedList()
	{
		head = nullptr;
	}

	// mutator functions
	void appendNode(char);
	int insertNode(char, int);
	int deleteNode(int);
	
	int numNodes() const
	{
		return countNodes(head);
	}
	
	char maxNode() const
	{
		return largeAlpha(head, head->alpha);
	}
	void displayList() const;
	int reverseNode();
	int searchNode(char);
	bool checkLetter(char);

	bool isEmpty();
};
#endif
