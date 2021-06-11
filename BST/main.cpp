#include <iostream>
#include "BST.h"
using std::cout; using std::endl;

int main() {
	BST myTree;

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

	return 0;
}