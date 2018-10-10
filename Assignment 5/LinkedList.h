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

public:
	LinkedList()
	{
		head = nullptr;
	}

	// mutator functions
	void appendNode(char);
	int insertNode(char, int);
	int deleteNode(int);
	void displayList() const;
	int reverseNode();
	int searchNode(char);
	bool checkLetter(char);
};
#endif
