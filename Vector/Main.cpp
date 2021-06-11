#include <iostream>
#include "Vector.h"
using std::cout; using std::endl;

int main(void) {
	Vector myVector(16);

	for (int i{ 0 }; i < 16; i++) {
		myVector.push(i);
	}

	myVector.deleteIndex(5);
	myVector.deleteIndex(4);
	myVector.deleteIndex(3);

	cout << "Testing operator overloading: \n";
	for (int i{ 0 }; i < myVector.size(); i++) {
		try {
			cout << myVector[i] << " ";
		}
		catch (OutOfBoundsIndexException& e) {
			std::cerr << "Exception caught: out of bounds error caught.\n";
		}
	}

	cout << "\nTest deleteIndex method: \n";
	try {
		myVector.deleteIndex(2);
	} catch (EmptyVectorException &e) {
		std::cerr << "\nException caught: vector was empty.";
	}
	

	for (int i{ 0 }; i < myVector.size(); i++) {
		try {
			cout << myVector[i] << " ";
		} catch (OutOfBoundsIndexException &e) {
			std::cerr << "Exception caught: out of bounds error caught.\n";
		}
	}

	cout << "\nTesting the popping method: \n";
	for (int i{ 0 }; i < 3; i++) {
		try {
			cout << myVector.pop_back() << " ";
		}
		catch (EmptyVectorException& e) {
			std::cerr << "\nException caught: The vector is currently empty.";
		}
	}

	cout << "\nTesting the insert method: \n";
	myVector.insert(2, 7);

	for (int i{ 0 }; i < myVector.size(); i++) {
		try {
			cout << myVector[i] << " ";
		}
		catch (OutOfBoundsIndexException& e) {
			std::cerr << "Exception caught: out of bounds error caught.\n";
		}
	}

	cout << "\nTesting the prepend method.\n";
	myVector.prepend(12);
	myVector.prepend(23);
	myVector.prepend(56);
	myVector.prepend(78);
	myVector.prepend(25);
	myVector.prepend(14);

	for (int i{ 0 }; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}

	cout << "\nTesting the remove function: \n";
	myVector.remove(78);

	for (int i{ 0 }; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}

	return 0;
}
