/*
*
* Anthony Modica
*
* Chapter 21, Binary Tree
*
* August 11, 2018
*
* IntBinaryTree.h
*
*/

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value;			// value in node
		TreeNode* left;		// pointer to left child node
		TreeNode* right;	// pointer to right child node
	};

	TreeNode* root;			// pointer to root node
	
	// private member functions
	void insert(TreeNode *&, TreeNode *&);
	void displayInOrder(TreeNode *) const;
	int getTreeLeaf(TreeNode *);
	int findHeight(TreeNode*);
	int findWidth(TreeNode*, int);

public:
	// Constructor
	IntBinaryTree()
	{
		root = nullptr;
	}

	void insertNode(int);
	
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	
	int leafCount() 
	{
		return getTreeLeaf(root);
	}
		int height()
	{
		return findHeight(root);
	}

	int width(int input)
	{
		return findWidth(root, input);
	}

	bool isEmpty();
	int isInteger();

};
#endif
