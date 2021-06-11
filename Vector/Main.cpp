#include <iostream>
#include "vector.h"
using std::cout; using std::endl;

int main(void) {
	vector myVector(5);

	/*for (int i{ 0 }; i < 6; i++) {
		myVector.push(i);
	}

	cout << "Testing operator overloading: \n";
	for (int i{ 0 }; i < myVector.size(); i++) {
		try {
			cout << myVector[i] << " ";
		}
		catch (OutOfBoundsIndexException& e) {
			std::cerr << "Exception caught: out of bounds error caught.\n";
		}
	}

	cout << "\nTest deleteIndex function: \n";
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

	cout << "\nTesting the popping function: \n";
	for (int i{ 0 }; i < 3; i++) {
		try {
			cout << myVector.pop_back() << " ";
		}
		catch (EmptyVectorException& e) {
			std::cerr << "\nException caught: The vector is currently empty.";
		}
	}

	cout << "\nTesting the insert function: \n";
	myVector.insert(2, 7);

	for (int i{ 0 }; i < myVector.size(); i++) {
		try {
			cout << myVector[i] << " ";
		}
		catch (OutOfBoundsIndexException& e) {
			std::cerr << "Exception caught: out of bounds error caught.\n";
		}
	}*/

	myVector.prepend(12);
	myVector.prepend(23);
	myVector.prepend(56);
	myVector.prepend(78);
	myVector.prepend(25);
	myVector.prepend(14);

	for (int i{ 0 }; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}

	return 0;
}
