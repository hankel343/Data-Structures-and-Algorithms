#include "BST.h"

//====================================
/* Tree traversal [private] methods */
//====================================

void BST::inOrder(Node* p) {
	if (p != nullptr) {
		inOrder(p->left);
		cout << p->m_data << " ";
		inOrder(p->right);
	}
}

void BST::ReverseInOrder(Node* p) {
	if (p != nullptr) {
		ReverseInOrder(p->right);
		cout << p->m_data << " ";
		ReverseInOrder(p->left);
	}
}

void BST::levelOrder(Node* p) {
	if (p == nullptr) return; //Corner case when tree is empty

	std::queue<Node*> Q;
	Q.push(p);

	while (!Q.empty()) {
		Node* current = Q.front(); //Store top of queue in ptr current
		cout << current->m_data << " "; //Visit/print node data

		//If children of current are not nullptr, enqueue them
		if (current->left) Q.push(current->left);
		if (current->right) Q.push(current->right);

		Q.pop(); //Removing the address of the front of the queue.
	}
}

//=================
/* Insert Method */
//=================

void BST::insert(int data) {
	FindInsertionPoint(rootPtr, data);
}

//Aux. to insert public method
void BST::FindInsertionPoint(Node*& p, int data) {
	if (p == nullptr) { //Insertion point found
		p = new Node(data);
	}
	else if (data < p->m_data) { //Insertion point will be in left subtr.
		FindInsertionPoint(p->left, data);
	}
	else { //Insertion point will be in right subtr.
		FindInsertionPoint(p->right, data);
	}
}

//=================
/* Search Method */
//=================

bool BST::search(int data) {
	return isInTree(rootPtr, data);
}

//Aux. to search method
bool BST::isInTree(Node* p, int data) {
	if (p == nullptr) {
		return false;
	}
	else if (data == p->m_data) {
		return true;
	}
	else if (data < p->m_data) {
		return isInTree(p->left, data);
	}
	else {
		return isInTree(p->right, data);
	}
}

//=================
/* Remove Method */
//=================

void BST::remove(int data) {
	if (rootPtr == nullptr) return;

	if (isInTree(rootPtr, data)) {
		removeHelper(rootPtr, data);
	}
	else {
		cout << endl << data << " was not found in the tree.\n";
	}
}

void BST::removeHelper(Node*& p, int data) {
	if (data < p->m_data) {
		removeHelper(p->left, data);
	}
	else if (data > p->m_data) {
		removeHelper(p->right, data);
	}
	else { //Node found - must process appropriately with branches
	 //Case 1: No child
		if (p->left == nullptr && p->right == nullptr) {
			delete p;
			p = nullptr;
		}
		else if (p->left == nullptr) { //Case 2: One child
			Node* temp{ p };
			p = p->right;
			delete temp;
		}
		else if (p->right == nullptr) { //Case 2: One Child
			Node* temp{ p };
			p = p->left;
			delete temp;
		}
		else { //Case 3: two children
			int replacementData{ getPredecessor(p->left) }; //initializes replacementData to the inOr. pred.
			p->m_data = replacementData; //Replace current node's data with inOrd. pred.'s data
			removeHelper(p->left, replacementData); //Delete inOrd. pred.
		}
	}
}

int BST::getPredecessor(Node* p) {

	while (p->right) {
		p = p->right;
	}

	return p->m_data;
}

//==========
/* Get Min*/
//==========

int BST::getMin() {
	if (rootPtr == nullptr) return INT_MIN; //error value

	Node* iter{ rootPtr };
	while (iter->left) {
		iter = iter->left;
	}

	return iter->m_data;
}

//======================================
/* Recursive implementation of getMin */
//======================================

int BST::recGetMin() {
	if (rootPtr == nullptr) return INT_MIN;
	else return RecGetMinHelper(rootPtr);
}

//Aux. to RecGetMin()
int BST::RecGetMinHelper(Node* p) {
	if (p->left == nullptr) {
		return p->m_data;
	}
	else {
		RecGetMinHelper(p->left);
	}
}

//=====================================
/* Recursive implementation of getMax*/
//=====================================

int BST::recGetMax() {
	if (rootPtr == nullptr) return INT_MAX;
	else return RecGetMaxHelper(rootPtr);
}

//Aux. to RecGetMax()
int BST::RecGetMaxHelper(Node* p) {
	if (p->right == nullptr) {
		return p->m_data;
	}
	else {
		RecGetMaxHelper(p->right);
	}
}

//==========
/* Get Max*/
//==========

int BST::getMax() {
	if (rootPtr == nullptr) return INT_MAX; //error value

	Node* iter{ rootPtr };
	while (iter->right) {
		iter = iter->right;
	}

	return iter->m_data;
}

//===============
/* getHeight() */
//===============

int BST::getHeight() {
	return calculateHeight(rootPtr);
}

//Aux. to getHeight()
int BST::calculateHeight(Node* p) {
	if (p == nullptr) return -1;

	return std::max(calculateHeight(p->left), calculateHeight(p->right)) + 1;
}

//=========================
/* printAscending Method */
//=========================

void BST::printAscending() {
	inOrder(rootPtr);
}

//=========================
/* printDescending Method */
//=========================

void BST::printDescending() {
	ReverseInOrder(rootPtr);
}

//=======================
/* printByLevel Method */
//=======================

void BST::printByLevel() {
	levelOrder(rootPtr);
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

//================
/* getSuccessor */
//================

Node* BST::getSuccessor(int data) {
	Node* current = find(rootPtr, data); //returns mem. add. of node with specified data.
	if (current == nullptr) return nullptr;

	//case 1: current node has a right subtr.
	if (current->right != nullptr) {
		return getSubTreeMin(current->right); //returns mem. add. of min. in right subtr.
	}
	else { //case 2: no right subtr. - must walk tree to find best ancestor
		Node* successor{ nullptr };
		Node* ancestor{ rootPtr };
		while (ancestor != current) {
			if (current->m_data < ancestor->m_data) { //current is in left subtr. of ancestor
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {//current is in the right subtree of the ancestor
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

Node* BST::find(Node* rootPtr, int data) {
	if (data == rootPtr->m_data) { //Node with specified data found.
		return rootPtr;
	}
	else if (data < rootPtr->m_data) {
		find(rootPtr->left, data);
	}
	else if (data > rootPtr->m_data) {
		find(rootPtr->right, data);
	}
	else { //Node with specified data not in the tree.
		return nullptr;
	}
}

Node* BST::getSubTreeMin(Node* p) {
	if (p == nullptr) return nullptr;

	while (p->left) {
		p = p->left;
	}
	return p;
}

//=============
/* Destructor*/
//=============

BST::~BST() {
	destroy(rootPtr); //Releasing memory of dynamically allocated nodes
}

//Aux. to BST destructor - deallocates node memory with a post order traversal.
void BST::destroy(Node* p) {
	if (p != nullptr) {
		destroy(p->left);
		destroy(p->right);
		delete p;
	}
}