#include <iostream>
#include "vector.h"
using std::cout; using std::endl;

int main(void) {
	vector myVector(5);

	for (int i{ 0 }; i < 6; i++) {
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
	}

	return 0;
}
