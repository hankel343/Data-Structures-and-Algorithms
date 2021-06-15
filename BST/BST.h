#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <vector>
using std::cout; using std::endl;

struct Node {
	int m_data;
	Node* left;
	Node* right;

	//Constructors:
	Node() //Default
		: m_data{ 0 }, left{ nullptr }, right{ nullptr } {};
	Node(int data) //Overloaded
		: m_data{ data }, left{ nullptr }, right{ nullptr } {};
};

class BST {
private:
	/* Attributes */
	Node* rootPtr; //Pointer to the root of the tree.

	/* Private helper methods */

	//Aux. to insert public method
	void FindInsertionPoint(Node*& p, int data);

	//Aux. to BST destructor - deallocates node memory with a post order traversal.
	void destroy(Node* p);

	//Aux. to search method
	bool isInTree(Node* p, int data);

	//Aux. to RecGetMin method
	int RecGetMinHelper(Node* p);

	//Aux. to RecGetMax method
	int RecGetMaxHelper(Node* p);

	//Aux. to getHeight()
	int calculateHeight(Node* rootPtr);

	//Aux. to remove()
	void removeHelper(Node*& p, int data);

	/* Tree traversal methods */
	void inOrder(Node* p);
	void ReverseInOrder(Node* p);
	void levelOrder(Node* p);

	/* Utility functions */
	Node* find(Node* rootPtr, int data); //walks tree to find node with specified data from root node.
	int getPredecessor(Node* p);
	Node* getSubTreeMin(Node* p); //Returns the mem. address of the minimum value in the passed subtree.
	Node* createMinimalBST(std::vector<int> array, int start, int end); //Overloaded recursive utility to public func. of same name

public:
	//Constructor
	BST() : rootPtr{ nullptr } {};

	//Methods
	void insert(int data);
	bool search(int data);
	void remove(int data);
	int getMin();
	int recGetMin();
	int getMax();
	int recGetMax();
	int getHeight();
	void printAscending();
	void printDescending();
	void printByLevel();
	Node* createMinimalBST(std::vector<int> arr);
	Node* getSuccessor(int data);

	//Destructor
	~BST();
};


#endif