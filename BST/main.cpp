#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "BST.h"
using std::cout; using std::endl;

Node* createMinimalBST(std::vector<int> arr);
Node* createMinimalBST(std::vector<int> array, int start, int end); //Overloaded recursive utility to public func. of same name

int main(void) {
	BST myTree;
	srand((unsigned)time(NULL));

	myTree.insert(15);
	myTree.insert(10);
	myTree.insert(20);
	myTree.insert(8);
	myTree.insert(12);
	myTree.insert(6);
	myTree.insert(11);
	myTree.insert(17);
	myTree.insert(16);
	myTree.insert(25);
	myTree.insert(27);

	cout << "Graphical representation of the tree: \n";
	myTree.TPrint();

	cout << "Elements printed in ascending order: \n";
	myTree.printAscending();
	cout << endl;

	cout << "\nElements printed in descending order: \n";
	myTree.printDescending();
	cout << endl;

	cout << "\nElements printed by level: \n";
	myTree.printByLevel();
	cout << endl;

	cout << "\ndeleting 15 from the tree";
	myTree.remove(15);
	cout << "\ntree after deletion of 15: \n";
	myTree.printAscending();
	cout << endl;

	cout << "\ndeleting 15 from the tree";
	myTree.remove(15);
	cout << "\ntree after deletion of 15: \n";
	myTree.printAscending();
	cout << endl;

	int key = 9;
	int key2 = 15;
	cout << "\nIs " << key << " in the tree? --> " <<
		(myTree.search(key) ? "Yes" : "No") << endl;

	cout << "Is " << key2 << " in the tree? --> " <<
		(myTree.search(key2) ? "Yes" : "No") << endl;
	cout << endl;

	cout << "Minimum value in the tree: " << myTree.getMin() << endl;
	cout << "Maximum value in the tree: " << myTree.getMax() << endl;

	cout << "\nCalling recursive implementation of getMin function: " << myTree.recGetMin() << endl;
	cout << "Calling recursive implementation of getMax function: " << myTree.recGetMax() << endl;

	cout << "\nThe height of the binary tree is: " << myTree.getHeight() << endl;


	int data{ 6 };
	cout << "\nSuccessor value of 6: ";
	cout << myTree.getSuccessor(data)->m_data << endl;
	data = 27;
	cout << "Successor value of " << data << ":\n";
	if (myTree.getSuccessor(data) == nullptr) {
		cout << "Either the data entered has no successor or the node doesn't exist in the tree.\n";
	}
	else {
		cout << myTree.getSuccessor(data)->m_data << endl;
	}

	cout << "\n=======================================================\n";
	cout << "Creating a tree of minimum height given a sorted array: \n";
	cout << "=======================================================\n";

	//Create minimum height tree
	std::vector<int> nums(10);
	unsigned long j;
	for (j = 0; j < 10; j++) { //Populate nums with 10 random numbers 0 - 20
		nums[j] = rand() % 20;
	}
	std::sort(nums.begin(), nums.end()); //Sort array of random numbers


	Node* minHeightRoot{ createMinimalBST(nums) };
	BST minHeightTree(minHeightRoot);
	
	cout << "\nGraphical representation of the min height tree: \n";
	minHeightTree.TPrint();

	return 0;
}

//=====================
/* createMinimalTree */
//=====================
Node* createMinimalBST(std::vector<int> arr) {
	return createMinimalBST(arr, 0, arr.size() - 1);
}

//Recursive util. to public function of same name
Node* createMinimalBST(std::vector<int> arr, int start, int end) {
	if (end < start) { //Array is empty or base of recursion has been found, will make bottom nodes leaves
		return nullptr;
	}

	int mid = (start + end) / 2; //Determine the middle array index.
	Node* n = new Node(arr[mid]); //Create new node with array at mid's value
	n->left = createMinimalBST(arr, start, mid - 1); //n's left child will be assigned a return value (mem. address) 
	n->right = createMinimalBST(arr, mid + 1, end); //Same situation as one line above but for n's right child
	return n; //Return memory address to previous activation record in the stack
}