/*
*
* Anthony Modica
*
* Chapter 21, Binary Tree
*
* August 11, 2018
*
* IntBinaryTree.cpp
*
* Additional files needed to compile this program:
* IntBinaryTree.h
*
*/

#include "stdafx.h"
#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

// ********************************************************
// name:      insertNode
// called by: main
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The insertNode function adds an integer onto the Binary Tree
// ********************************************************
void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode = nullptr;

	// create a new node and store num in it

	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// insert the node
	insert(root, newNode);
}

// ********************************************************
// name:      insert
// called by: insertNode
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The insertNode function inserts the integer passed from insertNode
// ********************************************************
void IntBinaryTree::insert(TreeNode *&root, TreeNode *&newNode)
{
	if (root == nullptr) // insert node
	{
		root = newNode;
	}
	else if (newNode->value < root->value)
	{
		insert(root->left, newNode); // inserts into left branch
	}
	else 
	{
		insert(root->right, newNode); // inserts into right branch
	}
}

// ********************************************************
// name:      displayInOrder
// called by: insertNode
// passed:    nothing
// returns:   1,-1
// calls:     nobody
// The insertNode function inserts the integer passed from insertNode
// ********************************************************
void IntBinaryTree::displayInOrder(TreeNode *root) const
{
	if (root)
	{
		displayInOrder(root->left);

		cout << root->value << endl;
		
		displayInOrder(root->right);
	}
}

// ********************************************************
// name:      getTreeLeaf
// called by: nobody
// passed:    nothing
// returns:   number of leaves
// calls:     nobody
// The getTreeLeaf function accepts tree pointer and returns the number of leaves
// ********************************************************
int IntBinaryTree::getTreeLeaf(TreeNode* root)
{    
	// check if there is a root
	if (root == nullptr)
	{
		return 0;
	}
	// increments the number of child nodes
	else if (root->left == nullptr && root->right == nullptr) 
	{
		return 1;
	}
	else
	{
		// recursively add both the right and left tree leaf
		return (getTreeLeaf(root->left) + getTreeLeaf(root->right));
	}
}

// ********************************************************
// name:      findHeight
// called by: main
// passed:    nothing
// returns:   height of tree
// calls:     nobody
// The findHeight function compares the nodes on the left and right
// to see which side is bigger to determine the height (or levels) of the binary tree
// ********************************************************
int IntBinaryTree::findHeight(TreeNode* root)
{
	// returns when the function reaches the end of the binary tree
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		// recursively go through the right and left child nodes
		// and check which one is larger

		if (findHeight(root->left) < findHeight(root->right))
		{
			// account for the root node by adding one
			return (findHeight(root->right) + 1);
		}
		else
		{
			// account for the root node by adding one
			return (findHeight(root->left) + 1);
		}
	}
}

// ********************************************************
// name:      findWidth
// called by: main
// passed:    nothing
// returns:   height of tree
// calls:     nobody
// The findWidth function counts and returns the width of the tree, 
// which is the largest number of nodes in the same level
// ********************************************************
int IntBinaryTree::findWidth(TreeNode* root, int input)
{
	// check if the tree is empty
	if (root == nullptr)
	{
		return 0;
	}

	// the root of the binary tree is at level 0
	if (input == 0)
	{
		return 1;
	}
	// recursively go through program until input reaches 0 (or root node)
	// by decrementing the input by 1
	return findWidth(root->left, (input - 1)) + findWidth(root->right, (input - 1));
}

// ********************************************************
// name:      isEmpty
// called by: main
// passed:    nothing
// returns:   true. false
// calls:     nobody
// The isEmpty function checks if the stack is empty or not
// ********************************************************
bool IntBinaryTree::isEmpty()
{
	bool flag;

	if (!root)
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
int IntBinaryTree::isInteger()
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


